#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  vector<vector<bool>> visit(n, vector<bool>(m));
  struct Node {
    int x, y, d;
  };
  queue<Node> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '#') {
        q.push({i, j, 0});
        visit[i][j] = true;
      }
    }
  }
  
  auto inside = [&](int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
  };
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  int ans = 0;
  while (q.size()) {
    auto v = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int x = v.x + dx[i];
      int y = v.y + dy[i];
      if (inside(x, y) && !visit[x][y]) {
        visit[x][y] = true;
        q.push({x, y, v.d + 1});
        ans = max(ans, v.d + 1);
      }
    }
  }
  
  cout << ans << '\n';
  return 0;
}

  
