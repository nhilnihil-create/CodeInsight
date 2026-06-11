#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int g[5][5];
  memset(g, 0, sizeof(g));
  vector<int> path;
  path.push_back(0);
  path.push_back(1);
  path.push_back(2);
  path.push_back(3);
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x][y] = 1;
    g[y][x] = 1;
  }
  int ok = 0;
  while (true) {
    int connected_roads = 0;
    for (int i = 0; i < 3; i++) {
      int u = path[i];
      int v = path[i + 1];
      if (g[u][v] || g[v][u]) {
        connected_roads++;
      }
    }
    if (connected_roads == 3) {
      ok = 1;
    }
    if (!next_permutation(path.begin(), path.end())) {
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}