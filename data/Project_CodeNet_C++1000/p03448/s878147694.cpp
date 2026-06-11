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
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  for (int i = 0; i <= a; i++)
  for (int j = 0; j <= b; j++)
  for (int k = 0; k <= c; k++) {
    if (500 * i + 100 * j + 50 * k == x) ans++;
  }
  cout << ans << '\n';
}
