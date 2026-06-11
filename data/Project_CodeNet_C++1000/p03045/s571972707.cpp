#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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

/********************************
 * get_connected_component
 ********************************/
void _get_connected_component_dfs(
    unsigned int s,
    Graph &graph,
    std::vector<unsigned int> &components,
    std::vector<bool> &seen)
{
  Graph::Edges edges = graph.edges_[s];
  seen[s] = true;
  components.push_back(s);

  for(auto it = edges.begin(); it != edges.end(); it++) {
    if(seen[it->first] == true) continue;
    if(it->second.cap_ > 0) {
      _get_connected_component_dfs(it->first, graph, components, seen);
    }
  }
}

/**
 * \param components [OUT}
 */
void get_connected_component(
    unsigned int s,
    Graph &graph,
    std::vector<unsigned int> &components)
{
  std::vector<bool> seen(graph.n_v_);
  _get_connected_component_dfs(s, graph, components, seen);
}

int main()
{
  unsigned int N, M;
  std::cin >> N >> M;
  Graph g(N);

  for(unsigned int i=0; i<M; i++) {
    unsigned int x, y, z;
    std::cin >> x >> y >> z;
    x--; y--;  // 0-origin
    g.add_edge(x, y, 1);
    g.add_edge(y, x, 1);
  }

  std::map<unsigned int, unsigned int> node2cluster;
  int num_cluster = 0;
  for(unsigned int s = 0; s<N; s++) {
    if(node2cluster.find(s) != node2cluster.end()) {
      continue;
    }

    std::vector<unsigned int> components;
    get_connected_component(s, g, components);

    for(auto c: components) {
      node2cluster[c] = num_cluster;
    }
    num_cluster++;
  }

  std::cout << num_cluster << std::endl;
  return 0;
}
