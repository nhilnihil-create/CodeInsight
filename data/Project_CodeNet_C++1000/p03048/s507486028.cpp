#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i * r <= n; i++)
  for (int j = 0; j * g <= n - i * r; j++) {
    if ((n - i * r - j * g) % b == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
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
