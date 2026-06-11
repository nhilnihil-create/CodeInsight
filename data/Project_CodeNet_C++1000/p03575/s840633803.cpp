#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const int limit = 50;
int N,M;
vector<int> a(limit);
vector<int> b(limit);
vector<vector<bool>> graph(limit,vector<bool>(limit)); //辺
vector<bool> vis(limit); //頂点

void dfs (int v) {
  //vは頂点の場所
  //vを訪れていたらやめる
  if (vis[v]) return;
  vis[v] = true;
  for (int i = 0; i < N; i++) {
    if (graph[v][i]) dfs(i);
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--,b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  int ans = 0;

  for (int i = 0; i < M; i++) {

    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

    for (int j = 0; j < N; j++) vis[j] = false;

    dfs(0);

    bool connected = true;
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        connected = false;
      }
    }
    if (!connected) ans++;

    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  cout << ans << endl;

}
