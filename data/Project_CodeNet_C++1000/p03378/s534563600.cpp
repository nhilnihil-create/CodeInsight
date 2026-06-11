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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n + 1);
  for (int i = 0; i < m; i++) {
    int t; cin >> t; a[t]++;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  cout << min(a[x], a[n] - a[x]) << '\n';
}
