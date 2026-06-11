#include <iostream>
#include <string>

int main() {
  std::string s, temp = "";
  std::cin >> s;
  long long k;
  std::cin >> k;
  for (long long i = 0; i < k; i++) {
    if (s[i] != '1') {
      std::cout << s[i] << "\n";
      return 0;
    }
  }
  std::cout << 1 << "\n";
  return 0;
}