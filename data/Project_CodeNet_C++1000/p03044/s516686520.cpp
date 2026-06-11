#include <bits/stdc++.h>
using namespace std;

// ----------- define ---------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(), (x).end()
// ----------------------------------

const int N = 100005;

vector<ii> adj[N];
int color[N];

void dfs(int i, int p, int c) {
  color[i] = c;
  for (auto &j : adj[i]) {
    if (j.fi != p) {
      dfs(j.fi, i, c ^ (j.sc % 2));
    }
  }
}

void MAIN() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(ii(v, w));
    adj[v].push_back(ii(u, w));
  }
  dfs(1, 1, 1);
  for (int i = 1; i <= n; i++) {
    cout << color[i] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
