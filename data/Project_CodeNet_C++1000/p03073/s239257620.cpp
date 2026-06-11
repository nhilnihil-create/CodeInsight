#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();

  string x, y;
  rep(i, n) {
    x += (i & 1) ? '1' : '0';
    y += (i & 1) ? '0' : '1';
  }

  int dx = 0, dy = 0;
  rep(i, n) {
    if (s[i] != x[i]) ++dx;
    if (s[i] != y[i]) ++dy;
  }

  cout << min(dx, dy) << endl;
  return 0;
}
