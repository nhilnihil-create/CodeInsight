#include <algorithm>
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  string key = "keyence";
  bool ok = false;
  int n = s.size();
  rep(i, n) {
    rep(j, n) {
      if (s.substr(0, i) + s.substr(j, n - 1) == key) {
        ok = true;
      }
    }
  }

  std::cout << (ok ? "YES" : "NO") << std::endl;
  return 0;
}
