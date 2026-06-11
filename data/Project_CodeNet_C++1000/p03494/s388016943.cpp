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
  int n;
  cin >> n;
  int ans = 2e9;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    int cnt = 0;
    while (t % 2 == 0) {
      t /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << '\n';
}
