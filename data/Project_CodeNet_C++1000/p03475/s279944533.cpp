#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

signed main() {
  int n;
  cin >> n;
  vector<int> c(n - 1);
  vector<int> s(n - 1);
  vector<int> f(n - 1);
  for (int i = 0; i < n - 1; ++i) cin >> c[i] >> s[i] >> f[i];

  vector<int> t(n, 0);

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j <= i; ++j) {
      int _t = t[j] - s[i];
      int _s;
      if (_t <= 0)
        _s = s[i];
      else if (_t % f[i] == 0)
        _s = s[i] + _t;
      else
        _s = s[i] + _t + f[i] - (_t % f[i]);

      t[j] = _s + c[i];
    }
  }
  for (int i = 0; i < n; ++i) cout << t[i] << endl;
}
