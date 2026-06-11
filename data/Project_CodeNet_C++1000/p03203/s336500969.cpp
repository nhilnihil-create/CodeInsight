#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> all(m, vector<int>());
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    all[y].push_back(x);
  }
  int res = n;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    sort(all[i].begin(), all[i].end());
    for (int x : all[i]) {
      if (x <= i + cnt) {
        cnt += (x == i + cnt);
        continue;
      }
      res = min(res, x);
    }
  }
  cout << res << '\n';
  return 0;
}
