#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  double n, k;
  cin >> n >> k;
  double ans = 0;
  for (double i = 1; i <= n; i++) {
    ans += (1.0 / n) * pow(0.5, ceil(log(ceil(k / i)) / log(2)));
  }
  cout << fixed << setprecision(20) << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
