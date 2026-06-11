#define MOD_TYPE 1

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using multiInt = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
*/

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

inline void init_main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
template <typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val)
{
  fill((T *)array, (T *)(array + N), val);
}
#pragma endregion

int main()
{
  init_main();

  int i, j, bi;
  int n;
  cin >> n;
  int d[50];
  for (i = 0; i < n; ++i)
    cin >> d[i];

  bool dp_next[1 << 24] = {}, dp[1 << 24] = {};
  dp[1] = true;
  for (i = 0; i < n; ++i)
  {
    for (bi = 0; bi < (1 << 24); ++bi)
    {
      if (!(bi & (1 << d[i])))
      {
        dp_next[bi | (1 << d[i])] |= dp[bi];
      }
      if (d[i] != 0 && d[i] != 12 && !(bi & (1 << (24 - d[i]))))
      {
        dp_next[bi | (1 << (24 - d[i]))] |= dp[bi];
      }
    }
    for (bi = 0; bi < (1 << 24); ++bi)
    {
      dp[bi] = dp_next[bi];
      dp_next[bi] = false;
    }
  }

  int Max = 0, Min;
  bitset<24> bs;

  for (bi = 0; bi < (1 << 24); ++bi)
  {
    if (!dp[bi])
      continue;
    Min = INF;
    bs = bitset<24>(bi);
    for (i = 0; i < 24; ++i)
      for (j = i + 1; j < 24; ++j)
      {
        if (bs[i] && bs[j])
          Min = min(Min, min(j - i, 24 - (j - i)));
      }
    Max = max(Max, Min);
  }
  cout << Max << "\n";
  return 0;
}
