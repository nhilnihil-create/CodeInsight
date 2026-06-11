#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b > c + d) cout << "Left" << '\n';
  else if (a + b < c + d) cout << "Right" << '\n';
  else cout << "Balanced" << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
