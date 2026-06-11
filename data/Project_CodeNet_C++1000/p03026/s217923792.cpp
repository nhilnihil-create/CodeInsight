#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 10000;

int n, c[N], m, d[N];
vector<int> G[N];

void dfs(int x, int *ci) {
  d[x] = c[(*ci)++];
  rep(i, G[x].size()) {
    int to = G[x][i];
    if (d[to]) continue;
    dfs(to, ci);
  }
}

int main() {
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i, n) cin >> c[i];
  sort(c, c + n, greater<int>());
  for (int i = 1; i < n; i++) m += c[i];
  int ci = 0;
  dfs(0, &ci);
  printf("%d\n", m);
  rep(i, n - 1) printf("%d ", d[i]);
  printf("%d\n", d[n - 1]);
  return 0;
}