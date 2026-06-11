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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  int ans = 2e9;
  for (int i = 0; i < n - k + 1; i++) {
    ans = min(ans, a[i + k - 1] - a[i]);
  }
  cout << ans << '\n';
}
