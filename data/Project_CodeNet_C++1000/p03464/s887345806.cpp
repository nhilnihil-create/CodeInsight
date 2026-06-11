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
  
  int k; cin >> k;
  vi a(k);

  rep(i, k) cin >> a[i];

  auto f = [&](ll x) {
    rep(i, k) x -= x % a[i];
    return x;
  };

  ll left = 0, right = 1e18;
  while (right - left > 1) {
    ll mid = (right + left) / 2;
    if (f(mid) >= 2) right = mid;
    else left = mid;
  }

  if (f(right) != 2) {
    cout << -1 << endl;
    return (0);
  }

  cout << left+1 << " ";

  left = 0, right = 1e18;
  while (right - left > 1) {
    ll mid = (right + left) / 2;
    if (f(mid) > 2) right = mid;
    else left = mid;
  }

  cout << left << endl;
  
  return (0);
}