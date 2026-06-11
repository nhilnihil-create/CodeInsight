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

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

int main()
{

  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(50) << setiosflags(ios::fixed);
  ll n;
  cin >> n;
  vector<pll> v;
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    v.push_back(MP(a, b));
  }

  const auto comp = [](pll &p1, pll &p2) {
    return p1.first + p1.second > p2.first + p2.second;
  };
  sort(all(v), comp);

  ll ans = 0;
  rep(i, n)
  {
    ans += (i % 2 == 0 ? v[i].first : -v[i].second);
  }
  cout << ans << endl;
  return 0;
}
