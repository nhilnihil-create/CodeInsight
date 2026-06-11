#include <iostream>

int main()
{
  int A, B, X;
  std::cin >> A >> B >> X;
  if (X - A < 0 || X - A > B) std::cout << "NO" << std::endl;
  else std::cout << "YES" << std::endl;
}
