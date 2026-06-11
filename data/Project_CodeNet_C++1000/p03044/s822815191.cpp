#include <iostream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class EdgeInfo {
public:
  EdgeInfo(int cap): cap_(cap), orig_cap_(cap) {}

  int cap_;
  int orig_cap_;
};

class Edge {
public:
  Edge(unsigned int s, unsigned int t, EdgeInfo ei):
      s_(s), t_(t), ei_(ei) {}

  unsigned int s_, t_;
  EdgeInfo ei_;
};

// unordered graph
class Graph {
public:
  // key: to
  using Edges = std::map<unsigned int, EdgeInfo>;

  // n_v: number of verteces
  Graph(unsigned int n_v);

  // add edge
  // return true: success, false: failed
  bool add_edge(unsigned int from,
                unsigned int to,
                EdgeInfo ei);

  void show() const {
    for(auto it = edges_.begin(); it != edges_.end(); it++) {
      auto idx = std::distance(edges_.begin(), it);
      std::for_each(it->begin(), it->end(),
                    [idx](auto& item) -> void
                    {
                      std::cout << idx << ","
                                << item.first << ","
                                << item.second.cap_
                                << std::endl;
                    });
    }
  }

  // number of vertexes
  unsigned int n_v_;
  // edge information
  // Be arere edges_[i][j] results in compile error
  // because EdgeInfo default constructor is not defined.
  // Access it edges[i].at[j].
  // ([] with missing key allocate default instance).
  std::vector<Edges> edges_;
};

Graph::Graph(unsigned int n_v)
    : n_v_(n_v)
{
  edges_.resize(n_v);
}

bool Graph::add_edge(
    unsigned int from,
    unsigned int to,
    EdgeInfo ei)
{
  if(from >= n_v_ || to >= n_v_ ||
     edges_[from].find(to) != edges_[from].end()) {
    std::cout << "add_edge failed: " << from << ", " << to << std::endl;
    return false;
  }

  edges_[from].insert(std::make_pair(to, ei));
  return true;
}

int reverse(int i)
{
  return i == 0 ? 1 : 0;
}

/**
 * color -1: undef, 0 or 1
 */
void set_color_dfs(
    unsigned int s,
    const Graph &g,
    std::vector<bool> &seen,
    std::vector<int> &color)
{
  Graph::Edges edges = g.edges_[s];
  seen[s] = true;
  for(const auto &e: edges) {
    auto to = e.first;
    auto ei = e.second;

    if(seen[to]) continue;
    seen[to] = true;
    color[to] = ei.cap_ % 2 == 0 ? color[s] : reverse(color[s]);
    set_color_dfs(to, g, seen, color);
  }
}


int main()
{
  int N;
  std::cin >> N;
  Graph g(N);

  for(int i=0; i<N-1; i++) {
    unsigned int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;   // 0-origin
    g.add_edge(u, v, w);
    g.add_edge(v, u, w);
    // std::cout << "inserted " << i << "-th edges"
    //           << " u = " << u
    //           << " v = " << v
    //           << std::endl;
    // g.show();
  }

  std::vector<bool> seen(N);
  std::vector<int> color;
  color.assign(N, -1);
  color[0] = 0;
  set_color_dfs(0, g, seen, color);

  for(auto c: color) {
    std::cout << c << std::endl;
  }

  return 0;
}
