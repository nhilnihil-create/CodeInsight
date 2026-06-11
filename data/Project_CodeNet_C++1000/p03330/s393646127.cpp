#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr int MOD_TYPE = 2;
constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

#pragma endregion

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  ll n, C;
  cin >> n >> C;
  ll d[510][510], c[510][510];
  rep(i, C) rep(j, C) cin >> d[i][j];
  rep(i, n) rep(j, n)
  {
    cin >> c[i][j];
    c[i][j]--;
  }

  ll cnt[510][3] = {};
  rep(i, n) rep(j, n)
  {
    ll k = (i + j) % 3;
    cnt[c[i][j]][k]++;
  }

  ll Min = LINF;
  rep(i1, C) rep(i2, C) rep(i3, C)
  {
    if (i1 == i2 || i2 == i3 || i3 == i1)
      continue;
    ll sum = 0;
    ll use[] = {i1, i2, i3};
    rep(ci, C) rep(j, 3)
    {
      sum += d[ci][use[j]] * cnt[ci][j];
    }
    Min = min(Min, sum);
  }

  cout << Min << endl;
  return 0;
}
