#include <iostream>

int main()
{
  int a, b, c;
  
  std::cin >> a >> b >> c;

  if (b == c) {
    std::cout << a << std::endl;
  } else if (a == c) {
    std::cout << b << std::endl;
  } else {
    std::cout << c << std::endl;
  }

  return 0;
}
