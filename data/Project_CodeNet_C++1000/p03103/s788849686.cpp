#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  freopen("in", "r", stdin);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ii> a(n);
  for (auto &i : a) cin >> i.fi >> i.sc;
  sort(all(a));
  int ans = 0;
  for (auto &i : a) {
    int t = min(i.sc, m);
    m -= t;
    ans += i.fi * t;
  }
  cout << ans << '\n';
}
