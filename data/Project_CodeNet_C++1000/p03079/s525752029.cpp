#include <iostream>
#include <string>

std::string solve(int a, int b, int c)
{
  const auto result = a == b && b == c;
  return result ? "Yes" : "No";
}

int main()
{
  int a, b, c;
  std::cin >> a >> b >> c;

  std::cout << solve(a, b, c) << std::endl;
}
