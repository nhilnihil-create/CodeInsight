#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 50;
vector<int> G[N];
bool visited[N];

void dfs(int pos) {
  visited[pos] = true;
  rep(i, G[pos].size()) {
    int to = G[pos][i];
    if (visited[to]) continue;
    dfs(to);
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }
  
  int ans = 0;
  rep(ri, m) {
    rep(i, n) G[i].clear();
    rep(i, m) {
      if (i == ri) continue;
      G[a[i]].push_back(b[i]);
      G[b[i]].push_back(a[i]);
    }
    rep(i, n) visited[i] = false;
    dfs(a[ri]);
    if (!(visited[b[ri]])) ++ans;
  }
  cout << ans << endl;
  return 0;
}