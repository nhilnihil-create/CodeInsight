#include <iostream>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <typename Container, class T>
bool contains(const Container& c, T v)
{
  return std::find(c.begin(), c.end(), v) != c.end();
}

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

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

bool
_find_path_dfs(
    unsigned int s, unsigned int t,
    Graph &g, std::vector<bool> &seen,
    std::vector<unsigned int> &route)
{
  // std::cout << "dfs: " << s << std::endl;
  Graph::Edges edges = g.edges_[s];
  seen[s] = true;
  route.push_back(s);

  if(s == t) return true;
  // std::cout << "s=" << s << " t=" << t << std::endl;

  // std::cout << s << " edges:" << edges.size() << std::endl;
  for(auto it = edges.begin(); it != edges.end(); it++) {
    if(seen[it->first] == true) continue;
    if(it->second.cap_ > 0 &&
       _find_path_dfs(it->first, t, g, seen, route)) {
      return true;
    }
  }
  route.pop_back();
  return false;
}

bool find_path_dfs(
    unsigned int s, unsigned int t,
    Graph &g,
    std::vector<unsigned int> &route)
{
  std::vector<bool> seen(g.n_v_);
  return _find_path_dfs(s, t, g, seen, route);
}

bool
_find_path_dfs(
    unsigned int s, const std::vector<unsigned int> &ts,
    Graph &g, std::vector<bool> &seen,
    std::vector<unsigned int> &route)
{
  // std::cout << "dfs: " << s << std::endl;
  Graph::Edges edges = g.edges_[s];
  seen[s] = true;
  route.push_back(s);

  if(contains(ts, s)) return true;
  // std::cout << "s=" << s << " t=" << t << std::endl;

  // std::cout << s << " edges:" << edges.size() << std::endl;
  for(auto it = edges.begin(); it != edges.end(); it++) {
    if(seen[it->first] == true) continue;
    if(it->second.cap_ > 0 &&
       _find_path_dfs(it->first, ts, g, seen, route)) {
      return true;
    }
  }
  route.pop_back();
  return false;
}

bool find_path_dfs(
    unsigned int s, const std::vector<unsigned int> &ts,
    Graph &g,
    std::vector<unsigned int> &route)
{
  std::vector<bool> seen(g.n_v_);
  return _find_path_dfs(s, ts, g, seen, route);
}

void update_residual_graph(
    Graph &g,
    std::vector<unsigned int> &route)
{
  // get max flow of the route
  int flow = -1;
  bool flow_set = false;
  auto frm = *(route.begin());
  for(auto to = route.begin() + 1;
      to != route.end(); to++) {
    if(flow_set) {
      flow = std::min(flow, g.edges_[frm].at(*to).cap_);
    } else {
      flow = g.edges_[frm].at(*to).cap_;
      flow_set = true;
    }
    frm = *to;
  }

  // std::cout << "flow:" << flow << std::endl;

  // generate residual graph
  frm = *(route.begin());
  for(auto to = route.begin() + 1;
      to != route.end(); to++) {
    g.edges_[frm].at(*to).cap_ -= flow;
    g.edges_[*to].at(frm).cap_ += flow;
    frm = *to;
  }
}

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

void _get_min_cut_dfs(
    unsigned int s,
    Graph &graph,
    std::vector<unsigned int> &components,  // [IN]
    std::vector<Edge> &edges_cut,           // [OUT]
    std::vector<bool> &seen)
{
  Graph::Edges edges = graph.edges_[s];
  seen[s] = true;

  for(auto it = edges.begin(); it != edges.end(); it++) {
    if(seen[it->first] == true) continue;
    if(it->second.cap_ > 0) {
      _get_min_cut_dfs(it->first, graph, components,
                       edges_cut, seen);
    }

    // if next vertex is not s-Cluster, and has revese flow, then cut
    if(std::find(components.begin(), components.end(), it->first)
       == components.end()) {
      auto &ei = graph.edges_[it->first].at(s);
      auto orig_cap = graph.edges_[s].at(it->first).orig_cap_;
      if(ei.cap_ > 0 && orig_cap > 0) {
        edges_cut.push_back(Edge(s,
                                 it->first,
                                 orig_cap));
      }
    }
  }
}

void get_min_cut(
    unsigned int s,
    Graph &graph,
    std::vector<unsigned int> &components,  // [IN]
    std::vector<Edge> &edges_cut)           // [OUT]
{
  std::vector<bool> seen(graph.n_v_);
  _get_min_cut_dfs(s, graph, components, edges_cut, seen);
}

struct XY {
  XY(int x_, int y_):
      x(x_), y(y_) {}

  int x;
  int y;

  std::string toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

  friend std::ostream& operator<<(std::ostream &os, const XY &rhs) {
    os << rhs.toString();
    return os;
  }

};

inline bool operator==(const XY &lhs, const XY &rhs) {
  return lhs.y == rhs.y && lhs.x == rhs.x;
}

inline bool operator!=(const XY &lhs, const XY &rhs) {
  return !(lhs == rhs);
}

inline bool operator<(const XY &lhs, const XY &rhs) {
  return lhs.y < rhs.y && lhs.x < rhs.x;
}

void add_edge(
    unsigned int s, unsigned int t, int cap,
    Graph &g)
{
  g.add_edge(s, t, cap);
  g.add_edge(t, s, 0);
}

int main()
{
  unsigned int N;
  std::cin >> N;
  Graph graph(2 + 2 * N); // source, target, nodes
  const unsigned int SRC = 0, TGT = 2*N + 1;

  std::vector<XY> reds, blues;
  for(unsigned int i=0; i<N; i++) {
    int x; std::cin >> x;
    int y; std::cin >> y;
    reds.push_back(XY(x, y));

    // graph.add_edge(SRC, i+1, 1);
    add_edge(SRC, i+1, 1, graph);
  }
  for(unsigned int i=0; i<N; i++) {
    int x; std::cin >> x;
    int y; std::cin >> y;
    XY xy(x, y);
    blues.push_back(xy);

    for(unsigned int j=0; j<N; j++) {
      if(reds[j] < xy) {
        // graph.add_edge(j+1, N+1+i, 1);
        add_edge(j+1, N+1+i, 1, graph);
      }
    }
    // graph.add_edge(N+1+i, TGT, 1);
    add_edge(N+1+i, TGT, 1, graph);
  }
  // graph.show();

  std::vector<unsigned int> ts = {TGT};
  std::vector<unsigned int> route;
  while(find_path_dfs(SRC, ts, graph, route)) {
    update_residual_graph(graph, route);
    route.clear();
  }

  std::vector<unsigned int> components;
  get_connected_component(SRC, graph,
                          components);
  // print_container(components, "components");

  std::vector<Edge> edges_cut;
  get_min_cut(SRC, graph, components, edges_cut);

  std::cout << edges_cut.size() << std::endl;

  return 0;
}
