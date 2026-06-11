#include <bits/stdc++.h>

template <typename T>
struct Edge {
  int from, to;
  T weight;
};

template <typename T>
class Graph {
 public:
  Graph(int n) : edges_(n) {}
  void AddEdge(int from, int to, T weight = T()) {
    edges_[from].push_back({from, to, weight});
  }
  const std::vector<Edge<T>>& Edges(int from) const { return edges_[from]; }
  int NumVertices() const { return edges_.size(); }

 private:
  std::vector<std::vector<Edge<T>>> edges_;
};

#if DEBUG
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << '\n';
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define wt(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

int main() {
  rd(ll, n);
  Graph<ll> g(n);
  rep(i, n - 1) {
    rd(ll, u, v, w);
    --u, --v;
    g.AddEdge(u, v, w);
    g.AddEdge(v, u, w);
  }
  vector<ll> color(n, -1);
  function<void(ll, ll, ll)> dfs = [&](ll node, ll parent, ll dist) {
    color[node] = dist % 2;
    for (const auto& e : g.Edges(node)) {
      if (e.to == parent) continue;
      if (color[e.to] != -1) continue;
      dfs(e.to, node, dist + e.weight);
    }
  };
  dfs(0, -1, 0);
  rep(i, n) wt(color[i]);
}
