#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> edge[110000];
bool done[110000];
queue<int> q;

bool bfs(int s) {
  done[s] = true;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); 
    q.pop();
    for (int v: edge[u]) {
      if (done[v]) continue;
      done[v] = true;
      q.push(v);
    }
  }
}

int main() {
  cin >> n >> m;
  
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    bfs(i);
    ans++;
  }
  
  cout << ans << endl;
  return 0;
}