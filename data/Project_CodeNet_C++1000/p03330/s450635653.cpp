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

  int n, m;
  cin >> n >> m;
  int d[30][30];
  rep(i, m) rep(j, m) cin >> d[i][j];
  int cnt[3][30] = {};
  rep(i, n) rep(j, n)
  {
    int c;
    cin >> c;
    c--;
    cnt[(i + j) % 3][c]++;
  }
  vector<int> p;
  rep(i, m - 3) p.push_back(0);
  p.push_back(1);
  p.push_back(2);
  p.push_back(3);
  ll Min = LINF;
  do
  {
    int index[3];
    rep(i, m)
    {
      if (p[i] != 0)
      {
        index[p[i] - 1] = i;
      }
    }
    ll sum = 0;
    rep(i, 3)
    {
      rep(j, m)
      {
        sum += cnt[i][j] * d[j][index[i]];
      }
    }
    Min = min(Min, sum);
  } while (NP(p));
  cout << Min << endl;
  return 0;
}
