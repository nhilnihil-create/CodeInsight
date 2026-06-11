#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void MAIN() {
  int n, m;
  cin >> n >> m;
  vector<ii> v;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    v.push_back(ii(l, r - 1));
    v.push_back(ii(r - 1, 2e9));
  }
  sort(all(v));
  int ans = 0;
  set<int> s;
  for (auto &i : v) {
    if (i.sc != 2e9) {
      s.insert(i.sc);
    } else if (s.count(i.fi)) {
      ans++;
      s.clear();
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
