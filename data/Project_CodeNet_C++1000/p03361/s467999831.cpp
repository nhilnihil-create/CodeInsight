#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  char grid[h][w];
  rep(i, h) rep(j, w) cin >> grid[i][j];

  rep(i, h) rep(j, w) {
    if (grid[i][j] == '#') {
      bool flag = false;
      //上確認
      if (i != 0) {
        if (grid[i - 1][j] == '#') flag = true;
      }
      //下確認
      if (i != h - 1) {
        if (grid[i + 1][j] == '#') flag = true;
      }
      //左確認
      if (j != 0) {
        if (grid[i][j - 1] == '#') flag = true;
      }
      //右確認
      if (j != w - 1) {
        if (grid[i][j + 1] == '#') flag = true;
      }
      if (!flag) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}