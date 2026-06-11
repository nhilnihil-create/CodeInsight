#include <bits/stdc++.h>
#define ll long long int
#define ii int
#define du double

#define vl vector<ll>
#define pb emplace_back
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define printv(v)                    \
  for (auto x : v) cout << x << " "; \
  cout << jmp;
#define jmp "\n"
#define vi vector<int>
#define vb vector<bool>
#define SORT(v) sort(v.begin(), v.end())
#define REV(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define SET(x, a) memset(x, a, sizeof(x))
#define si(x) x.size()
#define ff first
#define ss second
#define iin insert
using namespace std;
bool vis[100005];
// vl g[100005];
void dfs(ll s, vl g[]) {
  vis[s] = 1;
  for (auto x : g[s]) {
    if (!vis[x]) dfs(x, g);
  }
}
void solve() {
  ll n, m, x, y, z, ctr = 0;
  cin >> n >> m;
  vl g[n+1];
  memset(vis, 0, sizeof(vis));
  for (ll i = 0; i < m; i++) {
    cin >> x >> y >> z;
    //x--, y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  for (ll i = 1; i <= n; i++) {
    //ctr++;
    if (!vis[i]) dfs(i, g),ctr++;
  }

  cout << ctr << jmp;
}
int main() {
  ll t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}