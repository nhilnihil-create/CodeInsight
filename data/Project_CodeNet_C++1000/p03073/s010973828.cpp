#include <iostream>
#include <string>
#include <algorithm>
 
int main() {
  std::string s;
  std::cin >> s;
  std::string b(s.length(), '1'), w(s.length(), '0');
  long long bc = 0, wc = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (i % 2 == 1) {
      b[i] = '0';
      w[i] = '1';
    } else {
      b[i] = '1';
      w[i] = '0';
    }
  }
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] != b[i]) {
      bc++;
    }
    if (s[i] != w[i]) {
      wc++;
    }
  }
  std::cout << std::min(bc, wc) << "\n";
  return 0;
}