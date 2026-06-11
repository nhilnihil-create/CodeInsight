#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
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

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (a > b) a = b; }

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

  int d[4];
  rep(i, 4) d[i] = s[i] - '0';

  rep(bit, 1<<3) {
    int result = d[0];
    string ans;

    ans += s[0];

    rep(i, 3) {
      if (bit & (1<<i)) result += d[i+1], ans += '+';
      else result -= d[i+1], ans += '-';

      ans += s[i+1];
    }

    if (result == 7) {
      cout << ans << "=7" << endl;
      return (0);
    }
  }

  return (0);
}
