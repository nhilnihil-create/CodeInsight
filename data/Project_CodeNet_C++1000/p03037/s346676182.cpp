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
  vector<int> a(n + 2);
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    if (a[i] == m) ans++;
  }
  cout << ans << '\n';
}
