/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GROUPBYDIALOG_H
#define GROUPBYDIALOG_H

#include <QDialog>

#include <memory>

#include "librarymodel.h"

class GroupByDialogPrivate;
class Ui_GroupByDialog;

class GroupByDialog : public QDialog {
  Q_OBJECT

 public:
  GroupByDialog(QWidget* parent = nullptr);
  ~GroupByDialog();

 public slots:
  void LibraryGroupingChanged(const LibraryModel::Grouping& g);
  void accept();

signals:
  void Accepted(const LibraryModel::Grouping& g);

 private slots:
  void Reset();

 private:
  std::unique_ptr<Ui_GroupByDialog> ui_;
  std::unique_ptr<GroupByDialogPrivate> p_;
};

#endif  // GROUPBYDIALOG_H
