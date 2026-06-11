#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n;
  cin >> n;

  vector<double> t(n + 2), v(n + 2);
  for (auto i : irange(1L, n + 1)) {
    cin >> t[i];
    t[i] += t[i - 1];
  }
  for (auto i : irange(1L, n + 1)) {
    cin >> v[i];
  }

  // 加速終了時刻、減速開始時刻、終了速度
  vector<double> t1(n + 2), t2(n + 2), vv(n + 2);
  for (auto i : irange(1L, n + 2)) {
    if (vv[i - 1] > v[i]) {
      vv[i - 1] = v[i];
      for (auto j : irange(1L, i) | reversed) {
        auto dt = t[j] - t[j - 1];
        if (vv[j] + dt >= vv[j - 1]) {
          t1[j] = min(t1[j], t[j - 1] + (vv[j] + dt - vv[j - 1]) / 2.0);
          t2[j] = t[j] - (vv[j - 1] + (t1[j] - t[j - 1]) - vv[j]);
          break;
        } else {
          t1[j] = t2[j] = t[j - 1];
          vv[j - 1] = vv[j] + dt;
        }
      }
    }

    t1[i] = min(t[i - 1] + v[i] - vv[i - 1], t[i]);
    t2[i] = t[i];
    vv[i] = vv[i - 1] + t1[i] - t[i - 1];
  }

  double ans = 0;
  for (auto i : irange(1L, n + 1)) {
    auto dt1 = t1[i] - t[i - 1];
    auto dt2 = t2[i] - t1[i];
    auto dt3 = t[i] - t2[i];
    ans += vv[i - 1] * dt1 + dt1 * dt1 / 2.0;
    ans += (vv[i - 1] + dt1) * dt2;
    ans += vv[i] * dt3 + dt3 * dt3 / 2.0;
  }

  cout << setprecision(10) << ans << endl;
}