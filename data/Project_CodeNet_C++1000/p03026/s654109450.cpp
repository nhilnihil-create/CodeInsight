#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll N, p=0;
vector<ll> c;
ll d[200000];
vector<ll> edges[200000];

void dfs(int cur, int par) {
  d[cur] = c[p++];
  for (auto nxt: edges[cur]) {
    if (nxt == par)
      continue;
    dfs(nxt, cur);
  }
}

signed main() {
  cin >> N;
  rep(i,N-1){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  c.resize(N);
  rep(i,N) {
    cin >> c[i];
  }
  sort(begin(c),end(c));
  reverse(begin(c),end(c));

  ll sum = 0;
  for(ll i=1;i<N;i++)
    sum += c[i];

  dfs(0,-1);

  cout << sum << endl;
  rep(i,N)
    cout << d[i] << endl;
  return 0;
}

