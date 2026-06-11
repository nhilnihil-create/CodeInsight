#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size(), u = 1, v = 1;
  bool b = false;
  rep(i, n / 2) if(s[i] != s[n - 2 - i]) b = true;
  if(b || s[0] != '1' || s[n - 1] != '0') {
    cout << -1 << endl;
    return 0;
  }
  rep(i, n / 2 + 1) s[n / 2 + 1 + i] = '0';
  rep(i, n - 1) {
    cout << u << ' ' << ++v << '\n';
    if(s[n - 2 - i] == '1') u = v;
  }
}