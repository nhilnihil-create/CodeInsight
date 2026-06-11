/**
 *    author:  tourist
 *    created: 19.12.2019 15:01:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<int>> at(h);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    at[x].push_back(y);
  }
  int r = 0;
  for (int i = 1; i < h; i++) {
    sort(at[i].begin(), at[i].end());
    if (!at[i].empty() && at[i][0] <= r) {
      cout << i << '\n';
      return 0;
    }
    if (at[i].empty() || at[i][0] > r + 1) {
      ++r;
    }
  }
  cout << h << '\n';
  return 0;
}
