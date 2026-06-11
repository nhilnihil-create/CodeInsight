#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));

  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<vector<int>> ans;
  rep(i, h) rep(j, w) {
    if (a[i][j] % 2 == 0) continue;

    if (j + 1 < w && a[i][j + 1] % 2 == 1) {
      a[i][j]--;
      a[i][j + 1]++;
      ans.push_back({i, j, i, j + 1});
      continue;
    }

    if (i + 1 < h && a[i + 1][j] % 2 == 1) {
      a[i][j]--;
      a[i + 1][j]++;
      ans.push_back({i, j, i + 1, j});
      continue;
    }

    if (j + 1 < w) {
      a[i][j]--;
      a[i][j + 1]++;
      ans.push_back({i, j, i, j + 1});
      continue;
    }

    if (i + 1 < h) {
      a[i][j]--;
      a[i + 1][j]++;
      ans.push_back({i, j, i + 1, j});
      continue;
    }
  }

  cout << ans.size() << endl;
  for (auto move : ans) {
    printf("%d %d %d %d\n", move[0] + 1, move[1] + 1, move[2] + 1, move[3] + 1);
  }

  return 0;
}