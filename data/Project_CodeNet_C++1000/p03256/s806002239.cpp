#include <bits/stdc++.h>
using namespace std;

const int N = 201001;

int n, m, a[N][2], b[N];
char s[N];
vector<int> g[N];
queue<int> q;

int main(void) {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for(int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u][s[v] - 'A']++;
    a[v][s[u] - 'A']++;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i = 1; i <= n; i++)
    if(!a[i][0] || !a[i][1])
      q.push(i), b[i] = 1;
  while(!q.empty()) {
    int x = q.front(); q.pop();
    for(auto v : g[x])
      if(!b[v] && !--a[v][s[x] - 'A'])
	q.push(v), b[v] = 1;
  }
  for(int i = 1; i <= n; i++)
    if(!b[i]) return puts("Yes"), 0;
  return puts("No"), 0;
}
