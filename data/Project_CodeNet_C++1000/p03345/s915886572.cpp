#include <iostream>


int main() {
  long long a, b, c, k;
  std::cin >> a >> b >> c >> k;
  if(k % 2 == 1)
    std::cout << -(a - b);
  else
    std::cout << a - b;
}
