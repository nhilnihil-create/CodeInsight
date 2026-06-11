#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  long n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for (long i = 0; i < n; ++i) {
    std::cin >> s[i];
  }

  long abNum = 0;
  long endA = 0;
  long beginB = 0;
  long both = 0;

  for (long i = 0; i < n; ++i) {
    long len = s[i].length();
    if (s[i][len - 1] == 'A') ++endA;
    if (s[i][0] == 'B') ++beginB;
    if (s[i][len - 1] == 'A' && s[i][0] == 'B') ++both;
    for (long j = 0; j < len - 1; ++j) {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B') ++abNum;
    }
  }

  long addNum = std::min(endA, beginB);
  if (both > 0 && endA == both && beginB == both) --addNum;
  std::cout << abNum + addNum << std::endl;
}
