//
// Created by yarin on 06/11/17.
//

#include "DefaultGameLogic.h"
#include <iostream>
using namespace std;

/**
 * Constructor.
 */

DefaultGameLogic::DefaultGameLogic() : AbstractGameLogic(){}

/**
 * Destructor.
 */

DefaultGameLogic::~DefaultGameLogic() {
    delete this;
}

/**
 * This method checks the possible moves for a specific cell.
 * @param table the board's table.
 * @param size the size of the table.
 * @param rowPos the row of the cell.
 * @param colPos the column of the cell.
 * @return an array of possible moves for the cell.
 */

Location* DefaultGameLogic::clearMoveArea(Cell **table, int size, int rowPos, int colPos, int status) {
    int l = 0;
    Location* currentOptions = new Location(1,1);
    Location* option;
    //checking whether the vertical moves are possible.
    if (rowPos - 2 > 0 || rowPos + 2 <= size) {
        //checking the upper side
        if (rowPos - 2 > 0) {
            if (table[rowPos - 1][colPos].getStatus() != this->turn + 1
                && table[rowPos - 1][colPos].getStatus() > 0) {
                if (table[rowPos - 2][colPos].getStatus() == status) {
                    Location *option = new Location(rowPos - 2, colPos);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromUp(table, size, rowPos - 1, colPos, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
        //checking the lower side
        if (rowPos + 2 <= size){
            if (table[rowPos + 1][colPos].getStatus() != this->turn + 1
                && table[rowPos + 1][colPos].getStatus() > 0) {
                if (table[rowPos + 2][colPos].getStatus() == status) {
                    Location *option = new Location(rowPos + 2, colPos);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromDown(table, size, rowPos + 1, colPos, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
    }
    //checking whether the diagonal moves are possible.
    if (rowPos - 2 > 0 || rowPos + 2 <= size
        || colPos - 2 > 0 || colPos + 2 <= size) {
        //checking the upper left side
        if (rowPos - 2 > 0 && colPos - 2 > 0) {
            if (table[rowPos - 1][colPos - 1].getStatus() != this->turn + 1
                && table[rowPos - 1][colPos - 1].getStatus() > 0) {
                if (table[rowPos - 2][colPos - 2].getStatus() == status) {
                    Location *option = new Location(rowPos - 2, colPos - 2);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromUpLeft(table, size, rowPos - 1, colPos - 1, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
        //checking the upper right side
        if (rowPos - 2 > 0 && colPos + 2 <= size) {
            if (table[rowPos - 1][colPos + 1].getStatus() != this->turn + 1
                && table[rowPos - 1][colPos + 1].getStatus() > 0) {
                if (table[rowPos - 2][colPos + 2].getStatus() == status) {
                    Location *option = new Location(rowPos - 2, colPos + 2);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromUpRight(table, size, rowPos - 1, colPos + 1, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
        //checking the lower left side
        if (rowPos + 2 <= size && colPos - 2 > 0) {
            if (table[rowPos + 1][colPos - 1].getStatus() != this->turn + 1
                && table[rowPos + 1][colPos - 1].getStatus() > 0) {
                if (table[rowPos + 2][colPos - 2].getStatus() == status) {
                    Location *option = new Location(rowPos + 2, colPos - 2);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromDownLeft(table, size, rowPos + 1, colPos - 1, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
        //checking the lower right side
        if (rowPos + 2 <= size && colPos + 2 <= size) {
            if (table[rowPos + 1][colPos + 1].getStatus() != this->turn + 1
                && table[rowPos + 1][colPos + 1].getStatus() > 0) {
                if (table[rowPos + 2][colPos + 2].getStatus() == status) {
                    Location *option = new Location(rowPos + 2, colPos + 2);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromDownRight(table, size, rowPos + 1, colPos + 1, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
    }
    //checking whether the horizontal moves are possible.
    if (colPos - 2 > 0 || colPos + 2 <= size) {
        //checking the left side
        if (colPos - 2 > 0) {
            if (table[rowPos][colPos - 1].getStatus() != this->turn + 1
                && table[rowPos][colPos - 1].getStatus() > 0) {
                if (table[rowPos][colPos - 2].getStatus() == status) {
                    Location *option = new Location(rowPos, colPos - 2);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromLeft(table, size, rowPos, colPos - 1, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
        //checking the right side
        if (colPos + 2 <= size) {
            if (table[rowPos][colPos + 1].getStatus() != this->turn + 1
                && table[rowPos][colPos + 1].getStatus() > 0) {
                if (table[rowPos][colPos + 2].getStatus() == status) {
                    Location *option = new Location(rowPos, colPos + 2);
                    currentOptions[l] = *option;
                    l++;
                } else {
                    option = getFromRight(table, size, rowPos, colPos + 1, status);
                    if (option != NULL) {
                        currentOptions[l] = *option;
                        l++;
                    }
                }
            }
        }
    }
    if (l == 0) {
        delete  currentOptions;
        return NULL;
    } else {
        Location* option = new Location(NULL, 0);
        currentOptions[l] = *option;
        return currentOptions;
    }
}

/**
 * This method return the possible move from upper cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromUp(Cell **table, int size, int rowPos, int colPos, int status) {
    if(rowPos - 1 == 0) {
        return NULL;
    }
    int value = table[rowPos - 1][colPos].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos - 1, colPos);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromUp(table, size, rowPos - 1, colPos, status);
}

/**
 * This method return the possible move from right upper cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromUpRight(Cell **table, int size, int rowPos, int colPos, int status) {
    if(rowPos - 1 == 0 || colPos + 1 > size) {
        return NULL;
    }
    int value = table[rowPos - 1][colPos + 1].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos - 1, colPos + 1);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromUpRight(table, size, rowPos - 1, colPos + 1, status);
}

/**
 * This method return the possible move from right cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromRight(Cell **table, int size, int rowPos, int colPos, int status) {
    if(colPos + 1 > size) {
        return NULL;
    }
    int value = table[rowPos][colPos + 1].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos, colPos + 1);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromRight(table, size, rowPos, colPos + 1, status);
}

/**
 * This method return the possible move from lower right cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromDownRight(Cell **table, int size, int rowPos, int colPos, int status) {
    if(rowPos + 1 > size || colPos + 1 > size) {
        return NULL;
    }
    int value = table[rowPos + 1][colPos + 1].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos + 1, colPos + 1);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromDownRight(table, size, rowPos + 1, colPos + 1, status);
}

/**
 * This method return the possible move from lower cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromDown(Cell **table, int size, int rowPos, int colPos, int status) {
    if(rowPos + 1 > size) {
        return NULL;
    }
    int value = table[rowPos + 1][colPos].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos + 1, colPos);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromDown(table, size, rowPos + 1, colPos, status);
}

/**
 * This method return the possible move from lower left cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromDownLeft(Cell **table, int size, int rowPos, int colPos, int status) {
    if(rowPos + 1 > size || colPos - 1 == 0) {
        return NULL;
    }
    int value = table[rowPos + 1][colPos - 1].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos + 1, colPos - 1);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromDownLeft(table, size, rowPos + 1, colPos - 1, status);
}

/**
 * This method return the possible move from left cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromLeft(Cell **table, int size, int rowPos, int colPos, int status) {
    if(colPos - 1 == 0) {
        return NULL;
    }
    int value = table[rowPos][colPos - 1].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos, colPos - 1);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromLeft(table, size, rowPos, colPos - 1, status);
}

/**
 * This method return the possible move from upper left cells.
 * @param table the table of the board.
 * @param size the size of the table.
 * @param rowPos the row of the new move.
 * @param colPos the column of the new move.
 * @param status the wanted status to complete the move/flip.
 * @return the possible move.
 */

Location* DefaultGameLogic::getFromUpLeft(Cell **table, int size, int rowPos, int colPos, int status) {
    if(rowPos - 1 == 0 || colPos - 1 == 0) {
        return NULL;
    }
    int value = table[rowPos - 1][colPos - 1].getStatus();
    if (value == status) {
        Location* option = new Location(rowPos - 1, colPos - 1);
        return option;
    }
    if (value == turn + 1) {
        return NULL;
    }
    return getFromUpLeft(table, size, rowPos - 1, colPos - 1, status);
}