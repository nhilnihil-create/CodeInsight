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
  multiset<string> s;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string t; cin >> t;
    s.insert(t);
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    string t; cin >> t;
    auto it = s.find(t);
    if (it != s.end()) s.erase(it);
  }
  int ans = 0;
  for (auto i : s) {
    ans = max(ans, (int) s.count(i));
  }
  cout << ans << '\n';
}
