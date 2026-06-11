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
  
  string s; cin >> s;
  int n = si(s);

  int ans = 0;
  rep(i, n/2) {
    if (s[i] == s[n-i-1]) continue;
    if (s[i] == 'x') s.insert(s.begin() + n-i, 'x');
    else if (s[n-i-1] == 'x') s.insert(s.begin() + i, 'x');
    else {
      cout << -1 << endl;
      return (0);
    }
    --i;
    ++ans;
    ++n;
  }

  cout << ans << endl;
  
  return (0);
}