#include <bits/stdc++.h>

using namespace std;

bool ok(string s) {
  for (const auto& c : s) {
    if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int len = (int)s.size();
  int ans = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 1; j <= len - i; j++) {
      string ss = s.substr(i, j);
      if (ok(ss)) ans = max(ans, (int)ss.size());
    }
  }
  cout << ans << '\n';
  return 0;
}