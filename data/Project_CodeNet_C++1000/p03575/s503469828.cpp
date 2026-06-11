// I love
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

const int N = 55;

vector<int> adj[N];

int ans = 0;

int id[N], ch[N], cnt = 0;

void dfs(int i, int p) {
  id[i] = ch[i] = ++cnt;
  for (auto &j : adj[i]) {
    if (j == p) continue;
    if (id[j]) ch[i] = min(ch[i], id[j]);
    else {
      dfs(j, i);
      ch[i] = min(ch[i], ch[j]);
      if (id[i] < ch[j]) ans++;
    }
  }
}

void MAIN() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
