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
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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
  
  int n, m; cin >> n >> m;
  vector<vi> s(m);
  rep(i, m) {
    int k; cin >> k;

    rep(j, k) {
      int x; cin >> x;
      s[i].eb(x-1);
    }
  }

  vi p(m);
  rep(i, m) cin >> p[i];
  int ans = 0;

  rep(bit, 1<<n) {
    bool ok = true;
    rep(i, m) {
      int sum = 0;
      rep(j, si(s[i])) if (bit & (1<<s[i][j])) ++sum;

      if (sum % 2 != p[i]) ok = false;
    }

    if (ok) ++ans;
  }

  cout << ans << endl;
  
  return (0);
}