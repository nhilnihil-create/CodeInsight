#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100005];
bool visited[100005];
int coord[100005];
int cmx, cmn;
bool feasible;

void dfs(int ni, int pos) {
  if (visited[ni]) return;
  visited[ni] = true;
  coord[ni] = pos;
  cmx = max(cmx, pos);
  cmn = min(cmn, pos);
  for (auto x : graph[ni]) {
    if (visited[x.first]) {
      if (coord[x.first] - pos != x.second) {
        feasible = false;
      }
    } else {
      dfs(x.first, pos + x.second);
    }
    if (!feasible) break;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int mi = 0; mi < m; mi++) {
    int l, r, d;
    cin >> l >> r >> d;
    graph[l].push_back({r, d});
    graph[r].push_back({l, -d});
  }
  feasible = true;
  for (int ni = 0; ni < n; ni++) {
    if (!visited[ni]) {
      cmx = 0;
      cmn = 0;
      dfs(ni, 0);
      if (cmx - cmn > 1000000000) feasible = false;
    }
  }
  if (feasible) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
