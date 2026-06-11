#include <bits/stdc++.h>

int main() {
  std::string s;
  std::cin >> s;
  int64_t ans = s.size();

  for (int64_t i = 1; i < s.size(); i++) {
    if (s[i - 1] != s[i]) {
      ans = std::min(ans, std::max<int64_t>(i, s.size() - i));
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
