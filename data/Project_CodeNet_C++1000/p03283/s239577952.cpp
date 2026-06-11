#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,m,tc;
  cin >> n >> m >> tc;

  vector<vector<int>> a(n + 2);
  vector<pair<int,int>> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i].first >> t[i].second;
  }
  sort(t.begin(),t.end());
  for (int i = 0; i < m; i++) {
    a[t[i].first].push_back(t[i].second);
  }
  while(tc--) {
    int p,q;
    cin >> p >> q;

    int res = 0;
    for (int i = p; i <= q; i++) {
      int cnt = (int)a[i].size() - (a[i].end() - upper_bound(a[i].begin(), a[i].end(), q));
      res += cnt;
    }
    cout << res << '\n';
  }
  return 0;
}