#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll n, m;
vector<int> a, b;
vector<vector<bool>> graph;
vector<bool> visited;

void dfs(ll v) {
  visited[v] = true;
  rep(nv, n) {
    if (!graph[v][nv]) continue;
    if (visited[nv]) continue;
    dfs(nv);
  }
}

int main() {
  cin >> n >> m;

  a = b = vector<int>(m);
  graph = vector<vector<bool>>(n, vector<bool>(n, false));

  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  ll ans = 0;
  rep(i, m) {
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

    visited = vector<bool>(n, false);

    dfs(0);

    bool bridge = false;
    rep(j, n) bridge |= !visited[j];
    if (bridge) ans++;

    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  cout << ans << endl;

  return 0;
}
