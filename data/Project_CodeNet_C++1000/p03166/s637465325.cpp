#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////

const ll inf = 1LL<<60;

template<typename T>
struct Tsort {
  vector<T> max_costs;
  T max_cost;
  int n;
  WeightedGraph<T> g;
  vector<int> sorted_vertices;
  vector<int> indegree;

  Tsort(WeightedGraph<T> _g) {
    g = _g;
    n = _g.size();
    max_costs.assign(n, 0);
    indegree.assign(n, 0);
    for (int i=0; i<n; i++) {
      for (auto v : g[i]) indegree[v.to]++;
    }
    queue<int> que;
    for (int i=0; i<n; i++) {
      if (indegree[i] == 0) que.push(i);
    }
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (auto u : g[v]) {
        indegree[u.to] -= 1;
        max_costs[u.to] = max(max_costs[u.to], max_costs[v]+u.cost);
        if (indegree[u.to] == 0) que.push(u.to);
      }
      sorted_vertices.push_back(v);
    }
    max_cost = 0;
    for (int i=0; i<n; i++) max_cost = max(max_cost, max_costs[i]);
  }
};

int main()
{
  int n; cin >> n;
  int m; cin >> m;
  WeightedGraph<int> g(n);
  for (int i=0; i<m; i++) {
    int x, y; cin>>x>>y; x--; y--;
    g[x].push_back(edge<int>{y, 1});
  }
  Tsort<int> ts(g);
  cout << ts.max_cost << endl;

  return 0;
}
