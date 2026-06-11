#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005;

vector<ll> d(N, -1);
vector<P> G[N];
int c[N];

void dfs(int x) {
  rep(i, G[x].size()) {
    P p = G[x][i];
    int to = p.first;
    if (d[to] != -1) continue;
    d[to] = d[x] + p.second;
    c[to] = d[to] % 2;
    dfs(to);
  }
  return;
}

int main() {
  int n;
  cin >> n;
  rep(i, n-1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
  }
  d[0] = 0;
  c[0] = 0;
  dfs(0);
  rep(i, n) cout << c[i] << endl;
  return 0;
}