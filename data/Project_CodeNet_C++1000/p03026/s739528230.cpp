#pragma region Macros
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

const int MOD_TYPE = 2;
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

#pragma endregion

int n;
int ans[10010];
vector<int> E[10010];
int par[10010];
ll c[10010];

void dfs(int v, int &i)
{
  for (auto c : E[v])
  {
    if (c == par[v])
      continue;
    par[c] = v;
    dfs(c, i);
  }
  ans[v] = c[i];
  i++;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  int n;
  cin >> n;

  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  rep(i, n) cin >> c[i];
  sort(c, c + n);

  int index = 0;
  par[0] = -1;
  dfs(0, index);
  ll sum = 0;
  rep(i, n - 1) sum += c[i];
  cout << sum << "\n";
  rep(i, n) cout << ans[i] << (i == n - 1 ? "\n" : " ");
  return 0;
}
