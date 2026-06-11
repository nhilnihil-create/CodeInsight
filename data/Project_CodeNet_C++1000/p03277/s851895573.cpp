#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using edge = struct {
  int to;
  int cost;
};
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
#define BITS(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

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

ll merge_cnt(vector<ll> &a) {
  ll n = a.size();
  if (n <= 1) {
    return 0;
  }

  ll cnt = 0;
  vl b(a.begin(), a.begin() + n / 2);
  vl c(a.begin() + n / 2, a.end());

  cnt += merge_cnt(b);
  cnt += merge_cnt(c);

  ll ai = 0, bi = 0, ci = 0;
  // merge の処理
  while (ai < n) {
    if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
      a[ai++] = b[bi++];
    } else {
      cnt += n / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vl A(N, 0);
  REP(i, N) cin >> A[i];
  auto B = A;
  sort(ALL(B), REV(ll));

  ll left = -1;
  ll right = N;

  while (abs(right - left) > 1) {
    ll mid = left + (right - left) / 2;
    ll x = B[mid];
    vl S(N + 1, 0);
    FOR(i, 1, N + 1) { S[i] = S[i - 1] + ((A[i - 1] >= x) ? 1 : (-1)); }
    ll ans = merge_cnt(S); //転倒数
    if (ans <= (((N + 1) * N) / 2 / 2)) {
      right = mid;
    } else
      left = mid;
  }
  cout << B[right] << endl;
  return 0;
}
