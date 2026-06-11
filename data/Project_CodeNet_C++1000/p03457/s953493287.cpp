#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  t[0] = x[0] = y[0] = 0;
  int ct = 0, cx = 0, cy = 0;
  repe(i, 1, n) cin >> t[i] >> x[i] >> y[i];

  rep(i, 0, n) {
    ll dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (dist > t[i + 1] - t[i] || (dist - (t[i + 1] - t[i])) % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
