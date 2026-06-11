#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
  cin >> s;
  t = s;
  reverse(t.begin(), t.end());
  int n = s.size(), res = 0;
  for (int l = 0, r = 0; l < n || r < n;) {
    int cntl = 0, cntr = 0;
    while (l < n && s[l] == 'x') ++l, ++cntl;
    while (r < n && t[r] == 'x') ++r, ++cntr;
    res += abs(cntl - cntr);
    if (l < n && r < n && s[l] != t[r]) {
      cout << -1 << endl;
      return 0;
    }
    ++l, ++r;
  }
  cout << res / 2 << endl;
  return 0;
}