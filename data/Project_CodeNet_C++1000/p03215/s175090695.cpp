#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_temp>
using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;

const ll MOD = (ll)(1e9 + 7);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << setiosflags(ios::fixed);
  ll n, k;
  cin >> n >> k;
  ll a[1010];
  rep(i, n) cin >> a[i];
  ll csum[1010];
  csum[0] = 0;
  rep(i, n) csum[i + 1] = csum[i] + a[i];
  vector<ll> v;
  rep(l, n + 1) REP(r, l + 1, n + 1)
  {
    v.push_back(csum[r] - csum[l]);
  }
  bool usable[1010 * 1010];
  rep(i, 1010 * 1010) usable[i] = true;
  ll t = 1LL << 50;
  ll ans = 0;
  while (t != 0)
  {
    ll cnt = 0;
    vector<ll> unused;
    rep(i, v.size())
    {
      if (!usable[i])
        continue;
      if ((v[i] % (t * 2)) / t == 1)
      {
        cnt++;
      }
      else
      {
        unused.push_back(i);
      }
    }

    if (cnt >= k)
    {
      ans += t;
      for (auto un : unused)
        usable[un] = false;
    }
    t >>= 1;
  }
  cout << ans << endl;
  return 0;
}
