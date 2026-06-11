#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  int R(n / 2), L(n - 1 - R);
  char c = s[R];
  for (; R < n && s[L] == c && s[R] == c; R++, L--) {}
  int ret = R;
  cout << ret << '\n';
  return 0;
}