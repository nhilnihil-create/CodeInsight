#include <bits/stdc++.h>
using namespace std;

namespace {
int Do01BFS(int K, vector<int>* distances) {
  vector<int>& d = *distances;
  deque<int> q;
  d[1] = 0;
  q.push_back(1);
  while (!q.empty()) {  // Visits every node.
    auto now = q.front();
    q.pop_front();
    int next = (now + 1) % K;
    if (d[next] == INT_MAX) {  // Not visited.
      d[next] = d[now] + 1;
      q.push_back(next);
    }
    next = (now * 10) % K;
    if (d[next] > d[now]) {  // Updates shorter path.
      d[next] = d[now];
      q.push_front(next);
    }
  }
  return d[0] + 1;
}
}  // namespace

int main() {
  int K;
  cin >> K;
  // Distance of each mod K integers.
  vector<int> distances(K, INT_MAX);
  cout << Do01BFS(K, &distances) << endl;
}
