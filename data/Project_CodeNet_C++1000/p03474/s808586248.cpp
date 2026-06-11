#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>


int main()
{
  int A, B;
  std::cin >> A >> B;
  std::string code;
  std::cin >> code;

  bool is_postal = std::all_of(code.begin(), code.begin()+A,
                               [](char u) -> bool { return std::isdigit(u); });
  // std::cout << is_postal;

  is_postal = is_postal && code[A] == '-';
  // std::cout << is_postal;

  is_postal = is_postal && std::all_of(code.begin()+A+1, code.end(),
                                       [](char u) -> bool { return std::isdigit(u); });
  // std::cout << is_postal;

  std::cout << (is_postal ? "Yes" : "No") << std::endl;
  return 0;
}
