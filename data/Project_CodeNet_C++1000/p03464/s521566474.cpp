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
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}

inline void finish()
{
  cout << -1 << endl;
  exit(0);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(50) << setiosflags(ios::fixed);

  ll n;
  cin >> n;
  ll a[100010];
  rep(i, n) cin >> a[i];
  ll l = 2, r = 3;
  for (ll i = n - 1; i >= 0; --i)
  {
    l = CEIL(l, a[i]) * a[i];
    r = CEIL(r, a[i]) * a[i];
  }
  if (l == r)
    finish();
  cout << l << " " << r - 1 << endl;
  return 0;
}
