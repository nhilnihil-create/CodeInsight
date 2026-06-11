#include <iostream>
#include <algorithm>

int main()
{
  int A, B, C;
  std::cin >> A >> B >> C;
  std::cout << std::min(B/A,C);
  return 0;
}