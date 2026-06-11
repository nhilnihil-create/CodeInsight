#include <bits/stdc++.h>
using namespace std;
std::vector<long long> dijkstra(std::vector<std::vector<std::pair<int, long long>>> const& adj, int v0) {
    int n = adj.size();
    std::vector<long long> cost(n, -1);
    std::priority_queue<std::pair<long long, int>> pq;
    pq.push({0, v0});
    cost[v0] = 0;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        long long c = -x.first;
        int v = x.second;
        if (c > cost[v])
            continue;
        cost[v] = c;
        for (auto next : adj[v]) {
            if (cost[next.first] == -1 || cost[next.first] > c + next.second) {
                cost[next.first] = c + next.second;
                pq.push({-(c + next.second), next.first});
            }
        }
    }
    return cost;
}
int main() {
  int K;
  cin >> K;
  vector<vector<pair<int,long long>>> G(K);
  for (int i = 0; i < K; i++) {
    G[i].push_back({(i+1)%K,1});
    G[i].push_back({(10*i)%K,0});
  }
  cout << dijkstra(G,1)[0]+1;
}