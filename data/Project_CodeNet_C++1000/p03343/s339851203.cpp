#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k, q;
  cin >> n >> k >> q;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  int ans = 2e9;
  for (int i = 0; i < n; i++) {
    int now = a.at(i), it = 0;
    vector<vector<int>> G(n);
    for (int j = 0; j < n; j++) {
      if (a.at(j) >= now) G[it].emplace_back(a.at(j));
      else if (G[it].size() != 0) it++;
    }
    vector<int> keep;
    for (int j = 0; j <= it; j++) {
      sort(G[j].begin(), G[j].end());
      for (int ii = 0; ii + k <= G[j].size(); ii++) {
        keep.emplace_back(G[j][ii]);
      }
    }
    sort(keep.begin(), keep.end());
    if (keep.size() >= q) ans = min(ans, keep[q - 1] - keep[0]);
  }
  
  cout << ans << '\n';
}