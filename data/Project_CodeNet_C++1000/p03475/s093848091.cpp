#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> c(n), s(n), f(n);
  rep(i, 0, n - 1) cin >> c[i] >> s[i] >> f[i];

  rep(i, 0, n) {
    int t = 0;
    rep(j, i, n - 1) {
      if (t < s[j])
        t = s[j];
      else if (t % f[j] == 0)
        ;
      else {
        t = t + f[j] - t % f[j];
      }
      t += c[j];
    }
    cout << t << endl;
  }

  return 0;
}
