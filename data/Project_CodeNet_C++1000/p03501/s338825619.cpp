#include <iostream>

int main(void){
  int n, a, b, x;
  std::cin >> n >> a >> b;
  x = (a*n < b) ? a*n : b;
  std::cout << x << std::endl;
  return 0;
}