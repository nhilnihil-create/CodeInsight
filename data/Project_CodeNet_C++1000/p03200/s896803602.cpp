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
  string s;
  cin >> s;
  // BW -> WB
  int b = 0, ans = 0;
  for (auto &c : s) {
    if (c == 'B') b++;
    else ans += b;
  }
  cout << ans << '\n';
}
