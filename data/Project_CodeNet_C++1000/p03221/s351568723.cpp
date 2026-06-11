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
  vector<vi> t(n);
  vpi in(m);

  rep(i, m) {
    cin >> in[i].fi >> in[i].se;
    t[in[i].fi-1].eb(in[i].se);
  }

  auto f = [&](int p, int x) {
    string left, right;

    left = to_string(p);
    right = to_string(x);

    while (si(left) < 6) left = '0' + left;
    while (si(right) < 6) right = '0' + right;

    return left + right;
  };

  rep(i, n) sort(all(t[i]));

  rep(i, m) {
    int p = in[i].fi, y = in[i].se;

    int x = lower_bound(all(t[p-1]),y) - t[p-1].begin();

    cout << f(p, x+1) << endl;
  }

  return (0);
}
