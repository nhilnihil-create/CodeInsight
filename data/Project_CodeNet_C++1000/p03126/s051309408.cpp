#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      int t;
      cin >> t;
      a[t]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (a[i] == n) ans++;
  }
  cout << ans << '\n';
}
