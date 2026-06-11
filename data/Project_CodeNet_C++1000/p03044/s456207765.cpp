#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define ep emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007, MAX = 100001;

int n;
int ans[MAX];
vector<vpi> edge(MAX);

void dfs(int v, int parent, int color) 
{
  ans[v] = color;

  for (auto next : edge[v]) {
    int to = next.fi, weight = next.se;

    if (to == parent) continue;
    if (weight % 2) dfs(to, v, color ^ 1);
    else dfs(to, v, color);
  }
}

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  rep(i, n-1) {
    int u, v, w; cin >> u >> v >> w;
    edge[u-1].eb(v-1, w);
    edge[v-1].eb(u-1, w);
  }

  dfs(0, -1, 0);
  rep(i, n) cout << ans[i] << endl;

  return (0);
}
