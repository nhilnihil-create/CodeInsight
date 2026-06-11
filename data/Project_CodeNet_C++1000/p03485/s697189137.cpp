#include <iostream>

int main(){
  int a, b;
  std::cin >> a >> b;
  float x = (a + b) * 0.5;
  std::cout << int(x+0.5) << std::endl;
  return 0;
}