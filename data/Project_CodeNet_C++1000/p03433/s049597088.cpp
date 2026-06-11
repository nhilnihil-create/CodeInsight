#include <iostream>

int main(void){
  int n, a;
  std::cin >> n >> a;
  n %= 500;
  if(n <= a) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}