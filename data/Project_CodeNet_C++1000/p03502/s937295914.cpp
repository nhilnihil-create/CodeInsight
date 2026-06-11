#include <iostream>

int main(void){
  int x, tmp, f = 0, i;
  std::cin >> x;
  tmp = x;
  while(tmp != 0){
    f += tmp % 10;
    tmp /= 10;
  }
  if((x %= f) == 0) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}