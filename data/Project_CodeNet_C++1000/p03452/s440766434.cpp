#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int f[N];
ll dis[N];

void fail() {
  puts("No");
  exit(0);
}

int find(int k) {
  if(f[k] == k) return k;
  else {
    int fa = find(f[k]);
    dis[k] += dis[f[k]];
    return f[k] = fa;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i) f[i] = i;
  for(int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    int fx = find(x), fy = find(y);
    if(fx == fy) {
      if(dis[y] - dis[x] != z) fail();
    } else {
      f[fy] = fx;
      dis[fy] = dis[x] - dis[y] + z;
    }
  }
  puts("Yes");
  return 0;
}