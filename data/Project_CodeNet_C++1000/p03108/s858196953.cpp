#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int par[N], rnk[N], sz[N];
int findroot(int node) {
  if (par[node] == node)
    return node;
  else {
    par[node] = findroot(par[node]);
    return par[node];
  }
}
void dounion(int x, int y) {
  if (rnk[x] > rnk[y]) {
    par[y] = x;
    sz[x] += sz[y];
  }
  else if (rnk[x] < rnk[y]) {
    par[x] = y;
    sz[y] += sz[x];
  }
  else {
    par[x] = y;
    sz[y] += sz[x];
    rnk[y]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    sz[i] = 1;
    par[i] = i;
  }
  pair<int, int> edg[m];
  for (int i = 0; i < m; i++) {
    cin >> edg[i].first >> edg[i].second;
    edg[i].first--;
    edg[i].second--;
  }
  long long ans[m], cnt = (n - 1LL) * n / 2;
  for (int i = m - 1; i >= 0; i--) {
    ans[i] = cnt;
    int x = findroot(edg[i].first);
    int y = findroot(edg[i].second);
    if (x != y) {
      cnt -= 1LL * sz[x] * sz[y];
      dounion(x, y);
    }
  }
  for (int i = 0; i < m; i++)
    cout << ans[i] << '\n';
  return 0;
}