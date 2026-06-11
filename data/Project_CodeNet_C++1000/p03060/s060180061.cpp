// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

void MAIN() {
  int n; cin >> n;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  vector<int> c(n);
  for (auto &i : c) cin >> i;
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int x = 0, y = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        x += v[j];
        y += c[j];
      }
    }
    ans = max(ans, x - y);
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
  while (T--) MAIN();
}
