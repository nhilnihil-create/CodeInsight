#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  unordered_map<int, int> graph_;
  unordered_map<int, int> sizes_;
public:
  int Root(int key) {
    if (graph_.count(key) == 0 || graph_[key] == key) {
      return key;
    } else {
      return graph_[key] = Root(graph_[key]);
    }
  }

  bool Same(int key1, int key2) {
    return Root(key1) == Root(key2);
  }
  
  void Unite(int key1, int key2) {
    if (Same(key1, key2)) {
      return;
    }
    
    int root1 = Root(key1);
    int root2 = Root(key2);
    int size = Size(root1) + Size(root2);
    graph_[root1] = root2;
    sizes_[root2] = size;
  }

  int Size(int key) {
    int root = Root(key);
    return sizes_.count(root) > 0 ? sizes_[root] : 1;
  }
};


int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--, edges[i].second--;
  }
  
  int ans = 0;
  for (int i = 0; i < m; i++) {
    UnionFind uf;
    for (int j = 0; j < m; j++) {
      if (j == i) {
        continue;
      }
      
      uf.Unite(edges[j].first, edges[j].second);
    }
    
    int key = i == 0 ? 1 : 0;
    if (uf.Size(key) < n) {
      ans++;
    }
  }
  
  cout << ans << '\n';
  return 0;
}