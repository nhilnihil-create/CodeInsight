#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
  int to, cost;
  edge() {}
  edge(int t, int c) : to(t), cost(c) {}
};

vector<edge> G[100010];
int d[100010];

int main() {
  int K;
  cin >> K;

  for (int i = 0; i < K; i++) {
    G[i].push_back(edge((i + 1) % K, 1));
    if (i * 10 % K == i) continue;
    G[i].push_back(edge(i * 10 % K, 0));
  }

  deque<int> deq;
  fill(d, d + K, 1 << 30);
  d[1] = 0;
  deq.push_front(1);
  while (!deq.empty()) {
    int v = deq[0];
    deq.pop_front();
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      if (e.cost == 0) {
        deq.push_front(e.to);
      } else {
        deq.push_back(e.to);
      }
    }
  }
  cout << d[0] + 1 << endl;

  return 0;
}