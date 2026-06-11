#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

const int INF = 1000000007;
int n;
vector<int> g[200000];
int dist[200000];

void bfs(int s) {
  REP(i, n) dist[i] = INF;
  queue<int> que;
  que.push(s);
  dist[s] = 0;
  while (que.size()) {
    int u = que.front();
    que.pop();
    REP(i, g[u].size()) {
      int v = g[u][i];
      if (dist[v] == INF) {
        que.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
}

int main() {
  cin >> n;
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bfs(0);
  int diam = 0, x = 0;
  REP(i, n) {
    if (dist[i] == INF) continue;
    if (diam < dist[i]) {
      diam = dist[i];
      x = i;
    }
  }
  bfs(x);
  diam = 0;
  REP(i, n) {
    if (dist[i] == INF) continue;
    diam = max(diam, dist[i]);
  }
  cout << (diam % 3 == 1 ? "Second" : "First") << endl;
  return 0;
}