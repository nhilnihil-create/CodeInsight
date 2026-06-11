#include <iostream>
#include <cmath>

int main()
{
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  bool can_direct = std::abs(c - a) <= d;
  bool can_indirect = (std::abs(b - a) <= d &&
                       std::abs(c - b) <= d);

  int can = can_direct || can_indirect;
  std::cout << (can ? "Yes" : "No") << std::endl;

  return 0;
}
