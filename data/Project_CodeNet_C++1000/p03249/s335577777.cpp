#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void NO(int where = 0) {
//   dump(where);
  cout << -1 << endl;
  exit(0);
}

// 解けた〜たぴゃ〜 (ちょっとミスってたけど)
// D_iは相異なる，まじか〜

const int N = 1e5;
vector<vector<int>> g(N);
using Value = ll;
map<int, Value> dp[N];
map<int, int> sz[N];
int n;
Value dfs(int i, int p, int f = 0) {
  if(dp[i].count(p)) return dp[i][p];
  int cnt = 0;
  Value res = 0;
  if(f || p == -1) {
    // O(deg(i))
    // go only child
    sz[i][p] = 1;
    for(int j : g[i]) if(j != p) {
      cnt++;
      res += dfs(j, i, f);
      res += sz[j][i];
      sz[i][p] += sz[j][i];
    }
  } else {
    // O(1)
    dfs(i, -1, f);
    dfs(p, i, f);
    res = dp[i][-1] - (dp[p][i] + sz[p][i]);
    cnt = g[i].size() - 1;
    sz[i][p] = sz[i][-1] - sz[p][i];
  }
  return dp[i][p] = res;
}

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  vector<ll> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];
  vector<int> ord(n);
  iota((ord).begin(), (ord).end(), 0);
  sort((ord).begin(), (ord).end(), [&](int i, int j) { return d[i] < d[j]; });
  map<ll, int> mp;
  for(int i = 0; i < n; i++) mp[d[i]] = i;
  auto rnk = ord;
  for(int i = 0; i < n; i++) rnk[ord[i]] = i;
  vector<int> v(n);
  vector<pair<int,int>> ans;
  ll base = n - 2 * (n - 1);
  for(int i = n - 1; i >= 1; i--) {
    // dump(d[ord[i]], v[i], i);
    ll s = d[ord[i]] + (base + v[i] * 2);
    // dump(s);
    if(s >= d[ord[i]]) NO(1);
    if(!mp.count(s)) NO(2);
    v[rnk[mp[s]]] += v[i] + 1;
    int a = mp[s], b = ord[i];
    // dump(a, b);
    ans.emplace_back(a, b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  // dump("here");
  dfs(0, -1, 1);
  for(int i = 0; i < n; i++) if(d[i] != dfs(i, -1, 0)) NO();
  for(int i = 0; i < n - 1; i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  return 0;
}
