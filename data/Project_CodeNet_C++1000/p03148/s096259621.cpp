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
  int n, k;
  cin >> n >> k;
  vector<pll> v(n);

  rep(i, n)
  {
    cin >> v[i].second >> v[i].first;
  }
  sort(all(v), greater<pll>());
  ll sum = 0;
  bool used[100010] = {};
  smaller_queue<ll> que;
  ll kind = 0;
  rep(i, k)
  {
    sum += v[i].first;
    if (used[v[i].second])
    {
      que.push(v[i].first);
    }
    else
    {
      used[v[i].second] = true;
      kind++;
    }
  }

  ll Max = sum + kind * kind;
  REP(i, k, n)
  {
    if (que.empty())
      break;
    if (used[v[i].second])
      continue;
    sum += v[i].first;
    used[v[i].second] = true;
    sum -= que.top();
    que.pop();
    kind++;
    Max = max(Max, sum + kind * kind);
  }
  cout << Max << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
  solve();
  return 0;
}
