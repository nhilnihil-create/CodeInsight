#include <bits/stdc++.h>
using namespace std;

const int maxn = 1013;

int h, w;
bool used[maxn][maxn];
int d[maxn][maxn];

int main() {
  char a;
  cin >> h >> w;
  queue < pair < int, int > > q;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> a;
      if (a == '#') {
        q.push(make_pair(i, j));
        used[i][j] = 1;
      }
    }
  }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    if (!used[x - 1][y] && x > 1) {
      d[x - 1][y] = d[x][y] + 1;
      used[x - 1][y] = 1;
      q.push(make_pair(x - 1, y));
    }
    if (!used[x + 1][y] && x < h) {
      d[x + 1][y] = d[x][y] + 1;
      used[x + 1][y] = 1;
      q.push(make_pair(x + 1, y));
    }
    if (!used[x][y - 1] && y > 1) {
      d[x][y - 1] = d[x][y] + 1;
      used[x][y - 1] = 1;
      q.push(make_pair(x, y - 1));
    }
    if (!used[x][y + 1] && y < w) {
      d[x][y + 1] = d[x][y] + 1;
      used[x][y + 1] = 1;
      q.push(make_pair(x, y + 1));
    }
  }
  int ans = 0;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j)
      ans = max(ans, d[i][j]);
  }
  cout << ans << '\n';
}
