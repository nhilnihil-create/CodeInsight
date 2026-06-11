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

constexpr int MOD_TYPE = 1;
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

  int n, m;
  cin >> n >> m;
  vector<pair<int, pii>> query;
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    query.push_back(MP(b, MP(1, i)));
    query.push_back(MP(a, MP(2, i)));
  }
  sort(all(query));
  bool cut[100010] = {};
  int cnt = 0;
  vector<int> stock;
  for (auto q : query)
  {
    int type = q.second.first;
    int num = q.second.second;
    int pos = q.first;
    if (type == 2)
    {
      stock.push_back(num);
    }
    else
    {
      if (cut[num])
        continue;
      for (auto vi : stock)
      {
        cut[vi] = true;
      }
      cnt++;
      stock.clear();
    }
  }
  cout << cnt << endl;
  return 0;
}
