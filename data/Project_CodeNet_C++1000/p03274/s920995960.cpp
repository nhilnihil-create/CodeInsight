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

  int n, k; cin >> n >> k;
  vll plus, minus;

  rep(i, n) {
    int x; cin >> x;
    if (i == 0) minus.eb(0), plus.eb(0);

    if (x < 0) minus.eb(abs(x));
    else plus.eb(x);
  }

  sort(all(minus));
  int p = si(plus), m = si(minus);

  ll ans = MOD;
  rep(i, p) {
    int j = k - i;
    if (j >= m || j < 0) continue;

    chmin(ans, plus[i] * 2 + minus[j]);
  }

  rep(i, m) {
    int j = k - i;
    if (j >= p || j < 0) continue;

    chmin(ans, minus[i] * 2 + plus[j]);
  }

  if (k < p) chmin(ans, plus[k]);
  if (k < m) chmin(ans, minus[k]);

  cout << ans << endl;

  return (0);
}
