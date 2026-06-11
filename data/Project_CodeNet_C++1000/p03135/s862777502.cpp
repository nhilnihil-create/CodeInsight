#include <iostream>
#include <iomanip>
int main()
{
  int t, x;
  std::cin >> t >> x;
  std::cout << std::setprecision(10)  << 1.0 * t / x << std::endl;
  return 0;
}