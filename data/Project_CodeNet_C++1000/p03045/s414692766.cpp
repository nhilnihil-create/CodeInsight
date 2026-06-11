#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

int N, M;
vector<bool> used;
vector<vector<int> > G;

void dfs(int v) {
  if ( used[v] ) return;
  used[v] = true;

  for ( int &u: G[v] ) {
    if ( !used[u] ) dfs(u);
  }
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M;
  used.resize(N, false);
  G.resize(N);
  for ( int i = 0; i < M; i++ ) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int ans = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( !used[i] ) {
      ans++;
      dfs(i);
    }
  }

  cout << ans << endl;

  return 0;
}
