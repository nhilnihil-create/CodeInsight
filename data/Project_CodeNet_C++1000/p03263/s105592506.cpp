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

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (b < a) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int h, w; cin >> h >> w;
  int c[h][w];

  rep(i, h) rep(j, w) cin >> c[i][j];

  vector<pair<pi,pi>> ans;

  rep(i, h) {
    rep(j, w-1) {
      if (c[i][j] % 2) {
        --c[i][j];
        ++c[i][j+1];
        ans.eb(mp(i+1, j+1), mp(i+1, j+2));
      }
    }
  }

  rep(i, h-1) {
    if (c[i][w-1] % 2) {
      --c[i][w-1];
      ++c[i+1][w-1];
      ans.eb(mp(i+1, w), mp(i+2, w));
    }
  }

  printf("%d\n", si(ans));
  rep(i, si(ans)) {
    printf("%d %d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se.fi, ans[i].se.se);
  }
  
  return (0);
}