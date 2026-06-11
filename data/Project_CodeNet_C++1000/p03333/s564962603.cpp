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
  return a.first > b.first;
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
  vector<pair<pll, ll>> L(N);
  vector<pair<pll, ll>> R(N);
  REP(i, N) {
    ll l, r;
    cin >> l >> r;
    L[i] = make_pair(make_pair(-l, -r), i);
    R[i] = make_pair(make_pair(r, l), i);
  }
  sort(ALL(L));
  sort(ALL(R));
  ll a = 0;
  REP(_, 1) {
    ll ans = 0;
    ll pos = 0;
    ll nowl = 0;
    ll nowr = 0;
    vector<bool> used(N, false);
    REP(i, N) {
      // cout << P[i].first << "," << P[i].second << endl;
      if (i % 2 == 0) {
        while (used[L[nowl].second]) {
          nowl++;
        }
        used[L[nowl].second] = true;
        ll po = -L[nowl].first.first - pos;
        if (po > 0) {
          ans += po;
          pos = -L[nowl].first.first;
        }
      } else {
        while (used[R[nowr].second]) {
          nowr++;
        }
        used[R[nowr].second] = true;
        ll po = pos - R[nowr].first.first;
        if (po > 0) {
          ans += po;
          pos = R[nowr].first.first;
        }
      }
    }
    ans += abs(pos);
    a = max(a, ans);
  }
  REP(_, 1) {
    ll ans = 0;
    ll pos = 0;
    ll nowl = 0;
    ll nowr = 0;
    vector<bool> used(N, false);
    REP(i, N) {
      // cout << P[i].first << "," << P[i].second << endl;
      if (i % 2 == 1) {
        while (used[L[nowl].second]) {
          nowl++;
        }
        used[L[nowl].second] = true;
        ll po = -L[nowl].first.first - pos;
        if (po > 0) {
          ans += po;
          pos = -L[nowl].first.first;
        }
      } else {
        while (used[R[nowr].second]) {
          nowr++;
        }
        used[R[nowr].second] = true;
        ll po = pos - R[nowr].first.first;
        if (po > 0) {
          ans += po;
          pos = R[nowr].first.first;
        }
      }
    }
    ans += abs(pos);
    a = max(a, ans);
  }
  /*
   REP(_, 1) {
     ll ans = 0;
     ll pos = 0;
     REP(i, N) {
       if (i % 2 == 1) {
         ll po = P[i / 2].first - pos;
         if (po > 0) {
           ans += po;
           pos = P[i / 2].first;
         }
       } else {
         ll po = pos - P[N - 1 - (i / 2)].second;
         if (po > 0) {
           ans += po;
           pos = P[N - 1 - (i / 2)].second;
         }
       }
     }
     ans += abs(pos);
     a = max(a, ans);
   }*/

  cout << a << endl;
  return 0;
}
