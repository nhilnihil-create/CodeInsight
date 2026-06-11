#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
const int maxn = 200005;
std::vector<int> G[maxn];
int typ[maxn]; int deg[maxn][2];
inline void add_edge(int u, int v) {
  G[u].push_back(v);
}
inline void ins_edge(int u, int v) {
  add_edge(u, v); add_edge(v, u);
  deg[u][typ[v]] ++; deg[v][typ[u]] ++;
}

bool can_del(int x) {
  return (deg[x][0] == 0 || deg[x][1] == 0);
}
bool vis[maxn]; int n;
bool check() {
  std::queue<int> Q;
  for(int i = 1; i <= n; i ++) {
    if(can_del(i)) {
      Q.push(i); vis[i] = true;
    }
  }
  int cnt = 0;
  while(!Q.empty()) {
    int u = Q.front(); Q.pop(); cnt ++;
    for(int v : G[u]) {
      deg[v][typ[u]] --;
      if(!vis[v] && can_del(v)) {
        Q.push(v); vis[v] =  true;
      }
    }
  }
  return (cnt < n);
}

char buf[maxn];
int main() {
  int m; scanf("%d%d", &n, &m);
  scanf("%s", buf + 1);
  for(int i = 1; i <= n; i ++) typ[i] = buf[i] - 'A';
  for(int i = 1; i <= m; i ++) {
    int u, v; scanf("%d%d", &u, &v);
    ins_edge(u, v);
  }
  if(check()) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}