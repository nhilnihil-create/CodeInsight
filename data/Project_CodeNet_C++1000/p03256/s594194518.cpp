#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;

template<typename tp> inline void read(tp &x) {
  x = 0;char c = getchar();bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if (f) x = -x;
}
const int N = 3e5 + 233;
int n, m, ans = 0, tot = 0;
int col[N], inq[N], deg[N][2];
vector <int> g[N];
char str[N];

main(void) {
  read(n); read(m);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i ++)
    col[i] = str[i] - 'A';
  for (int i = 1; i <= m; i ++) {
    int x, y; read(x); read(y);
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x][col[y]] ++;
    deg[y][col[x]] ++;
  }
  queue <int> q;
  for (int i = 1; i <= n; i ++)
    if (!(deg[i][0] && deg[i][1]))
      q.push(i), inq[i] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop(); ++ tot;
    for (int i : g[u]) {
      -- deg[i][col[u]];
      if (!(deg[i][0] && deg[i][1])
          && !inq[i])
        q.push(i), inq[i] = true;
    }
  }
  puts(tot != n ? "Yes" : "No");
}
