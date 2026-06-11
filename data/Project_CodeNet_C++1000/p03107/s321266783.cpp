#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int zeroCnt = 0, oneCnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      zeroCnt++;
    }
    if (s[i] == '1') {
      oneCnt++;
    }
  }
  if (zeroCnt < oneCnt) {
    std::cout << zeroCnt * 2 << "\n";
  } else {
    std::cout << oneCnt * 2 << "\n";
  }
  return 0;
}