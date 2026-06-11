#include <bits/stdc++.h>

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; cin >> s;

  if (s[0] == s[1] && s[1] == s[2]) cout << "Yes\n";
  else if (s[1] == s[2] && s[2] == s[3]) cout << "Yes\n";
  else cout << "No\n";
  
  return (0);
}