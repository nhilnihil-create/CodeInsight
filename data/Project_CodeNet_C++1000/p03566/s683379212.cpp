#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> ts(n + 2), vs(n + 2);
  rep(i, n) cin >> ts[i + 1];
  rep(i, n) cin >> vs[i + 1];
  for (int i = 1; i <= n; i++) {
    vs[i] = min(vs[i], vs[i - 1] + ts[i]);
  }
  for (int i = n; i >= 1; i--) {
    vs[i] = min(vs[i], vs[i + 1] + ts[i]);
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    double t = ts[i], d1 = vs[i] - vs[i - 1], d2 = vs[i] - vs[i + 1];
    if (d1 > 0 && d2 > 0 && d1 + d2 > t) {
      double vl = min(vs[i - 1], vs[i + 1]), vd = vl + t - max(vs[i - 1], vs[i + 1]);
      ans += (vl * 2 + t) * t / 2 - vd * vd / 4;
    } else {
      ans += vs[i] * ts[i];
      if (d1 > 0) ans -= d1 * d1 / 2;
      if (d2 > 0) ans -= d2 * d2 / 2;
    }
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
