#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
using CostType = long long;
struct Edge {
  int src, dst;
  CostType cost;
  Edge(int src_, int dst_, CostType cost_ = 0) : src(src_), dst(dst_), cost(cost_) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return cost <= rhs.cost; }
  inline bool operator>(const Edge &rhs) const {
    return cost != rhs.cost ? cost > rhs.cost : dst != rhs.dst ? dst > rhs.dst : src > rhs.src;
  }
  inline bool operator>=(const Edge &rhs) const { return cost >= rhs.cost; }
};

vector<int> color;
bool dfs(const vector<vector<Edge> > &graph, int ver, int now) {
  color[ver] = now;
  for (Edge e : graph[ver]) {
    int nx = e.dst;
    if (color[nx] == now || (color[nx] == 0 && !dfs(graph, nx, -now))) return false;
  }
  return true;
}
bool is_bipartite(const vector<vector<Edge> > &graph) {
  int sz = graph.size();
  color.assign(sz, 0);
  REP(i, sz) if (color[i] == 0) {
    if (!dfs(graph, i, 1)) return false;
  }
  return true;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long n; int m; cin >> n >> m;
  vector<vector<Edge> > graph(n);
  REP(i, m) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(Edge(a, b));
    graph[b].emplace_back(Edge(b, a));
  }
  if (is_bipartite(graph)) {
    long long black = 0, white = 0;
    REP(i, n) {
      if (color[i] == 1) ++black;
      else ++white;
    }
    cout << black * white - m << '\n';
  } else {
    cout << n * (n - 1) / 2 - m << '\n';
  }
  return 0;
}
