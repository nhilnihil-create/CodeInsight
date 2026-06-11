#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int count{0};
  for(auto&& v : s)
    if (v == '2') count++;
  std::cout << count << std::endl;
}