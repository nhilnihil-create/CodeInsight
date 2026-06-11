#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong N, K;
  vector<lpair> xy;

  cin >> N >> K;
  xy.resize(N);
  for (auto &in: xy) {
    cin >> in.first >> in.second;
  }
  sort(ALL(xy));

  llong ans = LLONG_MAX;
  for (int xl = 0; xl < N; xl++) {
    for (int xr = xl + 1; xr < N; xr++) {
      vector<int> y;
      for (int i = xl; i <= xr; i++) {
        y.push_back(xy[i].second);
      }
      sort(ALL(y));
      for (int yl = 0; yl + K - 1 < y.size(); yl++) {
        int yr = yl + K - 1;
        ans = min(ans, (xy[xr].first - xy[xl].first) * (y[yr] - y[yl]));
      }
    }
  }

  cout << ans << endl;

  return 0;
}