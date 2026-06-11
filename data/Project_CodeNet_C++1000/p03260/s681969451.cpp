#include <iostream>

int main()
{
  int A, B;
  std::cin >> A >> B;
  if (A % 2 != 0 && B % 2 != 0) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
