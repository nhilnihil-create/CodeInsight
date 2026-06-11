#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

// https://atcoder.jp/contests/abc075/tasks/abc075_c

bool closedGraph(const unordered_map<int, vector<int>>& nodes, unordered_set<int>* visit, int startNode, int currentNode, int prevNode) {
  if (visit->find(currentNode) != visit->end()) {
    return currentNode == startNode;
  }
  visit->insert(currentNode);

  bool res = false;
  const auto iter = nodes.find(currentNode);
  for (const auto& node : iter->second) {
    if (node == prevNode) {
      continue;
    }
    res |= closedGraph(nodes, visit, startNode, node, currentNode);
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, vector<int>> nodes;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    nodes[a].emplace_back(b);
    nodes[b].emplace_back(a);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    unordered_set<int> visit;
    if (!closedGraph(nodes, &visit, i, i, -1)) ++ans;
  }
  if (ans == n) --ans;
  cout << ans << endl;
  return 0;
}