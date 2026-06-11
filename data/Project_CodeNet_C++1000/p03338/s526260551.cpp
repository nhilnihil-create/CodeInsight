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
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    set<char> x, y;
    for (int j = 0; j < i; j++) x.insert(s[j]);
    for (int j = i; j < n; j++) y.insert(s[j]);
    int cnt = 0;
    for (auto &j : x) if (y.count(j)) cnt++;
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}
