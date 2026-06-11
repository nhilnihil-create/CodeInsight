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
  int ans = 2e9;
  for (int i = 0; i <= s.size() - 3; i++) {
    ans = min(ans, (int) abs(stoi(s.substr(i, 3)) - 753));
  }
  cout << ans << '\n';
}
