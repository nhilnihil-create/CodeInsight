#include <iostream>
#include <vector>
#include <tuple>

int main(){
  int A,B;
  std::cin >> A >> B;

  std::vector<std::vector<int>> AB_arr(100, std::vector<int>(100));
  for(int i = 0; i < 50; i++){
    for(int j = 0; j < 100; j++){
      AB_arr[i][j] = 1;
    }
  }
  for(int i = 0; i < A-1; i++){
    AB_arr[2*(i/50)][2*(i%50)] = 0;
  }
  for(int i = 0; i < B-1; i++){
    AB_arr[99-2*(i/50)][2*(i%50)] = 1;
  }
  std::cout << "100 100\n";
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      std::cout << (AB_arr[i][j]==0?'.':'#');
    }
    std::cout << "\n";
  }
}
