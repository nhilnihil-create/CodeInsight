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
  int n, d, x;
  cin >> n >> d >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    ans += (d - 1) / t + 1;
  }
  cout << ans + x << '\n';
}
