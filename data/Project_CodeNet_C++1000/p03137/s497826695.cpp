#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> xs(m);
  vector<int> ds(m - 1);

  rep(i, m) cin >> xs[i];
  if (m <= n) {
    cout << 0 << endl;
  } else {
    sort(xs.begin(), xs.end());
    ll ans = 0;
    rep(i, m - 1) {
      ds[i] = xs[i + 1] - xs[i];
      ans += ds[i];
    }
    sort(ds.begin(), ds.end(), greater<int>());
    int cnt = 0;
    while (cnt < n - 1) {
      ans -= ds[cnt];
      cnt++;
    }
    cout << ans << endl;
  }
  return 0;
}
