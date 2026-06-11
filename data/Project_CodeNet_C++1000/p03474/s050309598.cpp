#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int a, b;
  string s;
  std::cin >> a >> b >> s;

  bool ok = true;
  rep(i, s.size()) {
    if (i == a) {
      if (s[a] != '-') {
        ok = false;
        break;
      } else {
        continue;
      }
    }
    if (!isdigit(s[i])) {
      ok = false;
      break;
    }
  }

  std::cout << (ok ? "Yes" : "No") << std::endl;
  return 0;
}
