#include <iostream>
#include <string>
#include <vector>

void fitInFrame(int numOfRow, int numOfColumn, std::vector<std::string>& mineField);
char countMine(int row, int column,const std::vector<std::string>& mineField);

int main() {
    int numOfRow = 0;
    int numOfColumn = 0;
    std::cin >> numOfRow >> numOfColumn;
    
    std::vector<std::string> mineField;
    std::string row;
    for(int i = 0; i < numOfRow; ++i) {
        std::cin >> row;
        mineField.push_back(row);
    }

    fitInFrame(numOfRow, numOfColumn, mineField);

    std::vector<std::string> convertedMineField(numOfRow);
    for (int i = 1; i <= numOfRow; ++i) {
        for(int j = 1; j <= numOfColumn; ++j) {
            if(mineField.at(i).at(j) == '.') {
                convertedMineField.at(i - 1).push_back(countMine(i, j, mineField));
            } else {
                convertedMineField.at(i - 1).push_back('#');
            }
        }
    }    
    for(std::string row : convertedMineField) {
        std::cout << row << std::endl;
    }    
}

void fitInFrame(int numOfRow, int numOfColumn, std::vector<std::string>& mineField) { 
    for(int i = 0; i < numOfRow; ++i) {
        mineField.at(i) = "." + mineField.at(i) + ".";
    }
    
    std::string frame;
    for(int i = 0; i < numOfColumn + 2; ++i) {
        frame += ".";
    }
        
    mineField.insert(mineField.begin(), frame);
    mineField.push_back(frame);
}

char countMine(int row, int column, const std::vector<std::string>& mineField) {
    int numOfMine = 0;
    for(int i = row - 1; i <= row + 1; ++i) {
        for(int j = column - 1; j <= column +1; ++j) {
            if(mineField.at(i).at(j) == '#') ++numOfMine;
        }
    }
    
    return '0' + numOfMine;
} 