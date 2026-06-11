#include <iostream>

int n, a, b;

int main(){
  std::cin >> n >> a >> b;

  std::cout << std::min(n*a, b) << std::endl;

  return 0;
}