#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << -1 << '\n';
  exit(0);
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    if (i == 1 && s[i] == '0') err();
    if (i == n && s[n] == '1') err();
    if (i < n && s[i] != s[n - i]) err();
  }
  int k = n;
  for (int i = n - 1; i >= 1; i--) {
    cout << k << " " << i << '\n';
    if (s[i] == '1') k = i;
  }
  return 0;
}