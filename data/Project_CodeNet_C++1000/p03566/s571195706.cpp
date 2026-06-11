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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << setiosflags(ios::fixed);
  int n;
  cin >> n;
  int t[210];
  ld v[210];
  rep(i, n) cin >> t[i + 1];
  rep(i, n) cin >> v[i + 1];
  t[0] = t[n + 1] = 0.0, v[0] = v[n + 1] = 0.0;
  ld sum = 0.0;
  ld graph[210][40100]; //i番目のグラフのf(0.5*j)

  int t_max = 0;
  rep(i, n) t_max += t[i + 1];

  int t_sum = 0;

  rep(i, n + 2)
  {
    for (int j = t_sum * 2; j <= (t_sum + t[i]) * 2; j++)
    {
      graph[i][j] = v[i];
    }

    for (int j = t_sum * 2 - 1; j >= 0; j--)
    {
      graph[i][j] = graph[i][j + 1] + 0.5;
    }

    for (int j = (t_sum + t[i]) * 2 + 1; j <= t_max * 2; j++)
    {
      graph[i][j] = graph[i][j - 1] + 0.5;
    }
    t_sum += t[i];
  }

  ld before = 0.0;
  ld ans = 0.0;
  for (int j = 0; j <= t_max * 2; ++j)
  {
    ld Min = INF;
    rep(i, n + 2) Min = min(Min, graph[i][j]);
    if (j != 0)
    {
      ans += (before + Min) * 0.5 / 2.0;
    }
    before = Min;
  }
  cout << ans << endl;
  return 0;
}
