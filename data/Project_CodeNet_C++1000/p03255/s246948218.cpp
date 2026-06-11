#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
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
const unsigned long long int llINF = 18446744073709551615;

using namespace std;
using ll = unsigned long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}
struct multi {
  ll first;
  ll second;
  ll third;
  multi(ll first, ll second, ll third)
      : first(first), second(second), third(third) {}
};
bool multicomp(const multi &a, const multi &b) {
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, X;
  ll ans = llINF;
  cin >> N >> X;
  vl A(N, 0);
  vl DP(N + 2, 0);
  REP(i, N) cin >> A[i];
  REP(i, N) { DP[i + 1] = DP[i] + A[N - 1 - i]; }
  FOR(k, 1, N + 1) {
    ll score = 0;
    FOR(i, 1, ceil((long double)N / (long double)k) + 1) {
      if (i == 1)
        score += 5 * (DP[min(N, i * k)] - DP[(i - 1) * k]);
      else
        score += ((2 * i) + 1) * (DP[min(N, i * k)] - DP[(i - 1) * k]);
    }
    ans = min(ans, score + ((k + N) * X));
  }
  cout << ans << endl;
  return 0;
}
