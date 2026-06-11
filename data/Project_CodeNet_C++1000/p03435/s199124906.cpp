#include<iostream>
#include<vector>

int main(void){

  std::vector<std::vector<int>> c(3, std::vector<int>(3));
  int c_sum = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      std::cin >> c[i][j];
      c_sum += c[i][j];
    }
  }

  if(c_sum == 3*(c[0][0] + c[1][1] + c[2][2])){
    std::cout << "Yes" << std::endl;
  }else{
    std::cout << "No" << std::endl;
  }

  return 0;

}