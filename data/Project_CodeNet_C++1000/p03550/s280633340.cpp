#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, x, y;
int a[N], f[2][N];

int dfs(int dep, int now) {
  if(~f[now][dep]) 
    return f[now][dep];
  f[now][dep] = abs(a[dep] - a[n]);
  for(int i = 1; i < n - dep; ++i) {
    if(now) 
      f[now][dep] = min(f[now][dep], dfs(i + dep, now ^ 1));
    else 
      f[now][dep] = max(f[now][dep], dfs(i + dep, now ^ 1));
  }
  return f[now][dep];
}

int main() {
  cin >> n >> x >> y;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  memset(f, -1, sizeof f);
  a[0] = y;
  printf("%d\n", dfs(0, 0));
  return 0;
}