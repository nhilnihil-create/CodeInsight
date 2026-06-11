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

void solve()
{
  ll a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a + 2), t(b + 2);
  s[0] = t[0] = -LINF;
  s[a + 1] = t[b + 1] = LINF / 4;
  rep(i, a) cin >> s[i + 1];
  rep(i, b) cin >> t[i + 1];
  rep(i, q)
  {
    ll x;
    cin >> x;
    ll Min = LINF;
    ll Ls = *(upper_bound(all(s), x) - 1);
    ll Lt = *(upper_bound(all(t), x) - 1);
    ll Rs = *(lower_bound(all(s), x));
    ll Rt = *(lower_bound(all(t), x));
    Min = min(Min, max(abs(Ls - x), abs(Lt - x)));
    Min = min(Min, max(abs(Rs - x), abs(Rt - x)));
    Min = min(Min, abs(Ls - x) * 2 + abs(Rt - x));
    Min = min(Min, abs(Ls - x) + abs(Rt - x) * 2);
    Min = min(Min, abs(Rs - x) * 2 + abs(Lt - x));
    Min = min(Min, abs(Rs - x) + abs(Lt - x) * 2);
    cout << Min << "\n";
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
  solve();
  return 0;
}
