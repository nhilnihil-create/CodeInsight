#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
 
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];


int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    to[u].push_back({v, w});
    to[v].push_back({u, w});
  }
   //bfs
    queue<int> que;
    que.push(0);
    visited[0] = true;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        ll d = dist[v];
        for (auto p : to[v]) {
            if (visited[p.first]){ continue;}
            dist[p.first] =  d+p.second;
            que.push(p.first);
            visited[p.first] = true;
        }
    }
  for (int i = 0; i < N; i++) cout << dist[i] % 2 << endl;
}
