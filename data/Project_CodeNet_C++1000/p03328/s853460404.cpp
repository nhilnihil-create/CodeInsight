#include <iostream>

int main()
{
  int a, b;

  std::cin >> a >> b;

  int t = b - a;

  t = (t * (t+1)) / 2;

  t = t - b;

  std::cout << t << std::endl;

  return 0;
}
