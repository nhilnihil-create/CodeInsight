#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

struct edge {
  int to, cost;
};

vector<vector<edge>> graph;
vector<bool> visited;
vector<int> dist;

void dfs(int s) {
  visited[s] = true;
  rep(i, graph[s].size()) {
    int to = graph[s][i].to, cost = graph[s][i].cost;
    if (visited[to]) continue;
    dist[to] = (dist[s] + cost) % 2;
    dfs(to);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  int n;
  cin >> n;
  graph.resize(n);
  visited.resize(n);
  dist.resize(n);
  rep(i, n) {
    visited[i] = false;
    dist[i] = INF;
  }
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    w %= 2;
    --u;
    --v;
    graph[u].push_back(edge{v, w});
    graph[v].push_back(edge{u, w});
  }
  dist[0] = 0;
  dfs(0);
  rep(i, n) cout << dist[i] << endl;
  return 0;
}
