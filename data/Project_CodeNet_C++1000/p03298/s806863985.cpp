#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 2147483647 / 2;
const long long int llINF = 9223372036854775807 / 2;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VV(T, a, b, c) vector<vector<T>>(a, vector<T>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define VVV(T, a, b, c, d)                                                     \
  vector<vector<vector<T>>>(a, vector<vector<T>>(b, vector<T>(c, d)))
#define SP(a) setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))
#define UNIQUE(vec)                                                            \
  do {                                                                         \
    sort(ALL((vec)));                                                          \
    (vec).erase(std::unique(ALL((vec))), (vec).end());                         \
  } while (0)

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vl S(N * 2, 0);
  REP(i, 2 * N) {
    char s;
    cin >> s;
    S[i] = s - 'a';
  }
  ll ans = 0;

  REP(state, 1 << (N - 1)) {
    //後半の状態がstate
    ll poyo = state;
    ll co = 0;
    REP(i, N) {
      if (poyo % 2 == 1)
        co++;
      poyo /= 2;
    }
    vl make1(co, 0);
    vl make2(N - co, 0);
    ll make1c = 0;
    ll make2c = 0;
    poyo = state;
    REP(i, N) {
      if (poyo % 2 == 1) {
        make1[make1c] = S[2 * N - i - 1];
        make1c++;
      } else {
        make2[make2c] = S[2 * N - i - 1];
        make2c++;
      }
      poyo /= 2;
    }
    // makeの状態を前半でも作れると良い
    vvl DP = VVL(make1.size() + 1, make2.size() + 1, 0);
    DP[0][0] = 1;
    REP(i, N) {
      vvl DPC = DP;
      REP(j, make1.size() + 1) {
        REP(k, make2.size() + 1) {
          if (j < make1.size() && S[i] == make1[j]) {
            DP[j + 1][k] += DPC[j][k];
          }
          if (k < make2.size() && S[i] == make2[k]) {
            DP[j][k + 1] += DPC[j][k];
          }
        }
      }
    }
    ans += DP[make1.size()][make2.size()];
    // REP(i, make1.size()) cout << (char)(make1[i] + 'a');
    // cout << ",";
    // REP(i, make2.size()) cout << (char)(make2[i] + 'a');
    // cout << endl;
    // cout << DP[make1.size()][make2.size()] << endl;
  }
  cout << ans * 2 << endl;

  return 0;
}
