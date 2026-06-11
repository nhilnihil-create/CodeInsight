#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
using Graph = vector<vector<bool>>;

vector<bool> visited;
ll N;

void dfs(Graph &G, ll v) {
  if (visited[v]) return;
  visited[v] = true;
  for (int i = 0; i < N; i++) {
    if (G[v][i]) {
      dfs(G, i);
    }
  }
}

int main() {
  ll M;
  cin >> N >> M;
  Graph node(N, vector<bool>(N, false));
  ll a, b;
  vector<pair<ll, ll>> es;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    a--;
    b--;
    node[a][b] = true;
    node[b][a] = true;
    es.push_back({a, b});
  }
  ll ans = 0;
  for (auto p : es) {
    a = p.first;
    b = p.second;
    node[a][b] = false;
    node[b][a] = false;
    visited.assign(N, false);
    dfs(node, 0);
    bool connected = true;
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        connected = false;
      }
    }
    if (!connected) ans++;
    node[a][b] = true;
    node[b][a] = true;
  }
  cout << ans << endl;
  return 0;
}