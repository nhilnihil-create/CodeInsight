#include <bits/stdc++.h>

#define fi first
#define se second
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

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s, t; cin >> s >> t;

  vector<string> se;
  rep(i, si(s) - si(t) + 1) {
    bool ok = true;
    rep(j, si(t)) if (s[i + j] != t[j] && s[i + j] != '?') ok = false;

    string tmp = s;
    if (ok) {
      rep(j, si(t)) tmp[i + j] = t[j];
      rep(j, si(s)) if (tmp[j] == '?') tmp[j] = 'a';

      se.emplace_back(tmp);
    }
  }

  if (se.empty()) cout << "UNRESTORABLE" << endl;
  else cout << *min_element(all(se)) << endl;
  
  return (0);
}