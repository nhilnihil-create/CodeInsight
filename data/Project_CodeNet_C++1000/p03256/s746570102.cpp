// Author: 23forever
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
typedef long long LL;
const int MAXN = 200000;
const int MAXM = 400000;
using namespace std;

inline void enableFileIO() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
}

inline int read() {
  int x = 0, w = 1;
  char c = ' ';

  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }

  return x * w;
}

int in[MAXN + 5][2], tot, head[MAXN + 5];
struct Edge {
  int to, nxt;
  Edge() {}
  Edge(int _to, int _nxt) : to(_to), nxt(_nxt) {}
}edge[MAXM + 5];
inline void add(int u, int v) {
  edge[tot] = Edge(v, head[u]);
  head[u] = tot++;
  edge[tot] = Edge(u, head[v]);
  head[v] = tot++;
}

int ch[MAXN + 5], n, m;
queue<int> que;

void init() {
//  enableFileIO();

  tot = 0;
  memset(head, -1, sizeof(head));
  
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) ch[i] = getchar() - 'A'; 
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    add(u, v);
    ++in[v][ch[u]];
    ++in[u][ch[v]];
  }
}

int sum;
bool vis[MAXN + 5];

int main() {
  init();
  
  for (int i = 1; i <= n; ++i) {
    if (!in[i][0] || !in[i][1]) {
      que.push(i);
      vis[i] = true;
      ++sum;
    }
  }

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    
    for (int i = head[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (!--in[v][ch[u]] && !vis[v]) {
        que.push(v);
        vis[v] = true;
        ++sum;
      }
    }
  }
  
  if (sum < n) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}