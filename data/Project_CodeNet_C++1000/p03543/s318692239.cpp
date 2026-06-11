#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  string s;
  cin >> s;
  if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])) {
    cout << "Yes" << '\n';
  }
  else cout << "No" << '\n';
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
