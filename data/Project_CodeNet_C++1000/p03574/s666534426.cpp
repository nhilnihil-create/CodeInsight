#include <iostream>
#include <string>

int main(void){
  int row, col, i, j;
  std::string str;
  std::cin >> row >> col;
  char board_c[row][col];
  int board_i[row][col];
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      board_i[i][j] = 0;
      std::cin >> board_c[i][j];
    }
  }
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      if(board_c[i][j] == '#'){
        if(i != 0){
          if(j != 0) board_i[i-1][j-1]++;
          board_i[i-1][j]++;
          if(j != col-1) board_i[i-1][j+1]++;
        }
        if(i != row-1){
          if(j != 0) board_i[i+1][j-1]++;
          board_i[i+1][j]++;
          if(j != col-1) board_i[i+1][j+1]++;
        }
        if(j != 0) board_i[i][j-1]++;
        if(j != col-1) board_i[i][j+1]++;
      }
    }
  }
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      if(board_c[i][j] == '#') std::cout << '#';
      else std::cout << board_i[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}