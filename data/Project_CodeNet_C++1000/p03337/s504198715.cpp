#include <iostream>
#include <algorithm>

int main() {
  int a, b;
  std::cin >> a >> b;
  int max = a + b;
  max = std::max(max, a*b);
  max = std::max(max, a-b);
  std::cout << max << std::endl;
  
  return 0;
}