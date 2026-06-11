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
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int t = i;
    int s = 0;
    while (t) {
      s += t % 10;
      t /= 10;
    }
    if (a <= s && s <= b) ans += i;
  }
  cout << ans << '\n';
}
