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
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
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

ll BipartiteGraph(const vector<vector<ll>> &g) {
  ll n = g.size();
  vector<ll> color(n, -1);
  ll white_cnt = 0;
  function<bool(ll, ll, ll)> dfs = [&](ll u, ll prev, ll c) {
    color[u] = c;
    if (c == 1)
      white_cnt++;
    for (auto v : g[u])
      if (v != prev) {
        if (color[v] == -1) {
          if (!dfs(v, u, 1 - c))
            return false;
        } else if (color[v] != 1 - c) {
          return false;
        }
      }
    return true;
  };
  if (!dfs(0, -1, 0))
    return -1;
  return white_cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M;
  cin >> N >> M;
  vl A(M), B(M);
  vvl G(N);
  map<pll, bool> MAP;

  REP(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  ll a = BipartiteGraph(G);
  if (a == -1) {
    cout << (N * (N - 1) / 2) - M << endl;
  } else {
    cout << a * (N - a) - M << endl;
  }

  return 0;
}
