#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
/*-------------------------------------------------*/
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

bool is_bipartite(const vector<vector<Edge> > &graph, vector<int> &color) {
  int n = graph.size();
  color.assign(n, 0);
  function<bool(int, int)> dfs = [&](int ver, int now) {
    color[ver] = now;
    for (const Edge &e : graph[ver]) {
      if (color[e.dst] == now || (color[e.dst] == 0 && !dfs(e.dst, -now))) return false;
    }
    return true;
  };
  REP(i, n) {
    if (color[i] == 0 && !dfs(i, 1)) return false;
  }
  return true;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long n; int m; cin >> n >> m;
  vector<vector<Edge> > graph(n);
  REP(_, m) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(a, b);
    graph[b].emplace_back(b, a);
  }
  vector<int> color;
  if (is_bipartite(graph, color)) {
    long long black = 0, white = 0;
    REP(i, n) ++(color[i] == 1 ? black : white);
    cout << black * white - m << '\n';
  } else {
    cout << n * (n - 1) / 2 - m << '\n';
  }
  return 0;
}
