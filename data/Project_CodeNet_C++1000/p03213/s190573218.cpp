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

  int n; cin >> n;
  map<int,int> m;

  rep2(i, 1, n) {
    int x = i;
    rep2(j, 2, sqrt(x)) {
      int cnt = 0;
      while (x % j == 0) {
        x /= j;
        ++cnt;
      }

      m[j] += cnt;
    }

    if (x != 1) ++m[x];
  } 

  ll ans = 0;
  int cnt_3 = 0, cnt_5 = 0, cnt_15 = 0, cnt_25 = 0;

  for (auto e : m) {
    ++e.se;

    if (e.se >= 3) ++cnt_3;
    if (e.se >= 5) ++cnt_5;
    if (e.se >= 15) ++cnt_15;
    if (e.se >= 25) ++cnt_25;
    if (e.se >= 75) ++ans;
  }

  auto nCr = [&](int x, int y) {
    ll res = 1;

    rep(i, y) res *= (x - i);
    rep2(i, 1, y) res /= i;

    return res;
  };

  ans += cnt_25 * (cnt_3 - 1);
  ans += cnt_15 * (cnt_5 - 1);
  ans += cnt_5 * (cnt_5 - 1) * (cnt_3 - 2) / 2;

  cout << ans << endl;

  return (0);
}
