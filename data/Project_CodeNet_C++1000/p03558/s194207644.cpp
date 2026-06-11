#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int k;
  cin >> k;
  
  // 重み付き無向(有向)グラフの隣接リスト
  vector<vector<pair<int, ll>>> G(k); // G:頂点数kのグラフの隣接リスト
  
  // mod K
  for (int i = 0; i < k; i++) {
    G[i].emplace_back(make_pair((i + 1) % k, 1));
    G[i].emplace_back(make_pair((i * 10) % k, 0));
  }
  
  vector<ll> d(k, 1e9);
  d[1] = 1;
  deque<int> dq;
  dq.push_back(1);
  while (!dq.empty()) {
    int v = dq.front();
    dq.pop_front();
    for (int i = 0; i < G[v].size(); i++) {
      if (d[G[v][i].first] <= d[v] + G[v][i].second) continue;
      d[G[v][i].first] = d[v] + G[v][i].second;
      if (G[v][i].second == 0) dq.push_front(G[v][i].first);
      else dq.push_back(G[v][i].first);
    }
  }
  
  cout << d[0] << '\n';
}