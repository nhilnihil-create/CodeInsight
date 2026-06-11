#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for (auto &i : b) cin >> i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int sum = c;
    for (int j = 0; j < m; j++) {
      int t; cin >> t;
      sum += t * b[j];
    }
    if (sum > 0) ans++;
  }
  cout << ans << '\n';
  return 0;
}
