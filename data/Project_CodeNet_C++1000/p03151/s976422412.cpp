#include <bits/stdc++.h>
#include <ostream>
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
  vll a(n), b(n);

  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vi c;
  ll sum = 0, ans = 0;

  rep(i, n) {
    ll d = a[i] - b[i];

    if (d < 0) sum += abs(d), ++ans;
    else c.eb(d);
  }

  sort(all(c),greater<int>());

  rep(i, si(c)) {
    if (sum <= 0) {
      cout << ans << endl;
      return (0);
    }

    sum -= c[i];
    ++ans;
  }
  
  if (sum > 0) cout << -1 << endl;
  else cout << ans << endl;

  return (0);
}
