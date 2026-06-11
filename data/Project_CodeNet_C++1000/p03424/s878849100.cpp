#include <iostream>

int main(void){
  int n, i;
  char c;
  std::cin >> n;
  for(i = 0; i < n; i++){
    std::cin >> c;
    if(c == 'Y'){
      std::cout << "Four" << std::endl;
      return 0;
    }
  }
  std::cout << "Three" << std::endl;
  return 0;
}