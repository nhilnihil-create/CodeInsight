#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  string a = "", b = "";
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'x') {
      ++cnt;
    } else {
      a.push_back(s[i]);
      b.push_back(s[i]);
    }
  }

  reverse(b.begin(), b.end());

  bool can = a == b;

  if (can) {
    int ans = 0, p = 0, q = s.size() - 1;
    while (p <= q) {
      if (s[p] == s[q]) {
        ++p, --q;
        continue;
      }
      if (s[p] == 'x')
        ++p;
      if (s[q] == 'x')
        --q;
      ++ans;
    }
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}