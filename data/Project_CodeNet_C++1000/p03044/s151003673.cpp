#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
const int MAX_N = 1e5+5;

vector<P> G[MAX_N];
vector<int> c;
void dfs(int v, int color = 0) {
  c[v] = color;
  for (auto p : G[v]) {
    if (c[p.first] != -1) continue;
    if (p.second%2) dfs(p.first, color^1);
    else dfs(p.first, color);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  c.assign(n, -1);
  rep(_, n-1) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  dfs(0);
  rep(i, n) cout << c[i] << endl;
}