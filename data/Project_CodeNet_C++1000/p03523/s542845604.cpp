#include <iostream>
#include <string>
#include <regex>

int main()
{
  std::string s;
  std::cin >> s;
  puts(std::regex_match(s, std::regex("A?KIHA?BA?RA?")) ? "YES" : "NO");
  return 0;
}
