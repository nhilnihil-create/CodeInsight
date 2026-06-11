#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using GraphC = vector<vector<char>>;

int main() {
  int H, W;
  cin >> H >> W;
  GraphC g(H, vector<char>(W));
  rep(y, 0, H) rep(x, 0, W) cin >> g[y][x];

  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, 1, 0, -1};

  int cnt = 0;
  rep(y, 0, H) {
    rep(x, 0, W) {
      if (g[y][x] != '#') continue;
      int nextIsNotBlack = 0;
      rep(i, 0, 4) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        if (g[ny][nx] != '#') nextIsNotBlack++;
      }
      if (nextIsNotBlack == 4) cnt++;
    }
  }

  if (cnt == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
