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

#define TLE 2e9

void MAIN() {
  int n, T;
  cin >> n >> T;
  int ans = TLE;
  for (int i = 0; i < n; i++) {
    int c, t;
    cin >> c >> t;
    if (t <= T) ans = min(ans, c);
  }
  if (ans == TLE) cout << "TLE" << '\n';
  else cout << ans << '\n';
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
