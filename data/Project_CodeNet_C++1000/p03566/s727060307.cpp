#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 1;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-11;

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

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  int n;
  cin >> n;
  vector<ld> t(n + 3), v(n + 2);
  t[0] = t[1] = 0, v[0] = 0;
  rep(i, n)
  {
    int ti;
    cin >> ti;
    t[i + 2] = t[i + 1] + ti;
  }
  rep(i, n) cin >> v[i + 1];
  t[n + 2] = t[n + 1], v[n + 1] = 0;

  ld Min[40010];
  fill(Min, Min + 40010, INF);
  rep(i, n + 2)
  {
    int l = t[i] * 2, r = t[i + 1] * 2;
    for (int ii = l; ii <= r; ii++)
    {
      Min[ii] = min(Min[ii], v[i]);
    }
    for (int ii = l, j = 0; ii >= 0; ii--, j++)
    {
      Min[ii] = min(Min[ii], v[i] + 0.5 * (ld)j);
    }
    for (int ii = r, j = 0; ii <= 40005; ii++, j++)
    {
      Min[ii] = min(Min[ii], v[i] + 0.5 * (ld)j);
    }
  }
  ld sum = 0;
  rep(i, t[n + 2] * 2)
  {
    sum += (Min[i] + Min[i + 1]) / 4.0;
  }
  cout << sum << endl;
  return 0;
}