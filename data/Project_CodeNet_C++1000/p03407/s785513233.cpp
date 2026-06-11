#include <iostream>

int main()
{
  int A, B, C;
  std::cin >> A >> B >> C;

  bool can = (C <= A + B);

  std::cout << (can ? "Yes" : "No") << std::endl;

  return 0;
}
