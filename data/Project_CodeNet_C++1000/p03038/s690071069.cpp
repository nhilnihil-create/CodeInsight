#include <bits/stdc++.h>
using namespace std;

// ----------- define ---------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(), (x).end()
// ----------------------------------

void MAIN() {
  int n, q;
  cin >> n >> q;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    m[-t]++;
  }
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    m[-v] += u;
  }
  int ans = 0;
  for (auto &i : m) {
    int t = min(i.sc, n);
    ans += -i.fi * t;
    n -= t;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
