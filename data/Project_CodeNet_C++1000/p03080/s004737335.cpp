#include <algorithm>
#include <iostream>
#include <string>

std::string solve(const std::string& s)
{
  const unsigned count = std::count(s.begin(), s.end(), 'R');
  return count * 2 > s.size() ? "Yes" : "No";
}

int main()
{
  int n;
  std::string s;
  std::cin >> n >> s;

  std::cout << solve(s) << std::endl;
}
