#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
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

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  queue<int> que;
  vector<vi> edge(n+m-1);
  vi in(n,0), ans(n);

  rep(i, n+m-1) {
    int a, b; cin >> a >> b;
    edge[a-1].eb(b-1);
    ++in[b-1];
  }

  rep(i, n) if (in[i] == 0) que.em(i);

  while (!que.empty()) {
    int q = que.front(); que.pop();

    for (auto to : edge[q]) {
      --in[to];
      if (in[to] == 0) {
        ans[to] = q+1;
        que.em(to);
      }
    }
  }

  rep(i, n) cout << ans[i] << endl;

  return (0);
}
