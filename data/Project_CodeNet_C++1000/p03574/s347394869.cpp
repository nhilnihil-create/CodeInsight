#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int H, W;
  cin >> H >> W;
  GraphC g(H, vector<char>(W));
  GraphI d(H, vector<int>(W, 0));
  queue<pint> q;
  rep(y, 0, H) {
    rep(x, 0, W) {
      cin >> g[y][x];
      if (g[y][x] == '#') {
        d[y][x] = 1;
        q.push(pint(y, x));
      }
    }
  }

  int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    int y = now.first, x = now.second;

    rep(i, 0, 8) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if (g[ny][nx] == '#') continue;
      d[ny][nx] += d[y][x];
    }
  }

  rep(y, 0, H) {
    rep(x, 0, W) {
      if (g[y][x] == '#')
        cout << '#';
      else
        cout << d[y][x];
    }
    cout << endl;
  }

  return 0;
}
