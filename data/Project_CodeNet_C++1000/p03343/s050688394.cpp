#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int a[N], f[N], vs[N];
priority_queue<int> q, p;

bool cmp(int x, int y) {
  return a[x] < a[y];
}

int main() {
  int n, len, Q;
  cin >> n >> len >> Q;
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    f[i] = i;
  }
  sort(f + 1, f + 1 + n, cmp);
  int ans = 1e9;
  for(int i = 1; i <= n; ++i) {
    int o = f[i];
    for(int j = 1; j <= n; ++j) {
      if(vs[j]) continue;
      int k = j;
      for(; k <= n && !vs[k]; k++) p.push(-a[k]);
      k--;
      while(p.size() >= len) {
        q.push(p.top());
        p.pop();
      }
      while(!p.empty()) p.pop();
      j = k;
    }
    vs[o] = 1;
    int res = 0, be = -1;
    while(!q.empty()) {
      res++;
      if(res == Q) be = -q.top();
      q.pop();
    }
    if(be != -1) ans = min(ans, be - a[o]);
    else break;
  }
  printf("%d\n", ans);
  return 0;
}