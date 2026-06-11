#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  uint64_t count = 0;
  uint64_t black = 0;
  rep(i, s.size()) {
    if (s[i] == 'W') {
      count += black;
    } else {
      black++;
    }
  }

  std::cout << count << std::endl;
  return 0;
}
