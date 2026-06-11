#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
 
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
 
void dfs(int now, ll d) {
  visited[now] = true;
  dist[now] = d;
  for (auto p : to[now]) {
    if (visited[p.first]) continue;
    dfs(p.first, d + p.second);
  }
}
 
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
  dfs(0, 0);
  for (int i = 0; i < N; i++) cout << dist[i] % 2 << endl;
}
