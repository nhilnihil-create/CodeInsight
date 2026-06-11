// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <cmath>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>
// #include <windows.h>
using namespace std;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = V<VV<T>>;
template<class T1, class T2> using P = pair<T1, T2>;
using I = int;
using D = double;
using B = bool;
using C = char;
using S = string;
using LL = long long;
using LD = long double;
using ULL = unsigned long long;
using PII = P<I, I>;
using VPII = V<PII>;
using PLL = P<LL, LL>;
using VPLL = V<PLL>;
using VI = V<I>;
using VVI = VV<I>;
using VLL = V<LL>;
using VVLL = VV<LL>;
using VC = V<C>;
using VVC = VV<C>;
using VS = V<S>;
using VVS = VV<S>;
using VB = V<B>;
using VVB = VV<B>;
#define REP(type, i, n) for (type i = 0; i < (type)(n); ++i)
#define REP2(type, i, m, n) for (type i = (m); i < (type)(n); ++i)
#define REPR(type, i, n) for (type i = (n)-1; i >= 0; --i)
#define REPR2(type, i, m, n) for (type i = (n)-1; i >= (m); --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTR(a, type) sort(ALL(a), greater<type>())
#define SORTF(a, comp) sort(ALL(a), comp)
#define REVERSE(a) reverse(ALL(a))
#define SIZE(a, type) ((type)(a).size())
#define bit_search(bit, n) REP(LL, bit, 1LL<<(n))
#define bit_check(bit, i) ((bit>>(i)) & 1)
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) (lower_bound(ALL(a), (x)) - a.begin())
#define bisect_right(a, x) (upper_bound(ALL(a), (x)) - a.begin())
#define INPUT(a) REPx(&x, a) cin >> x;
#define INPUT2(a) REPx(&x, a) INPUT(x);
#define INPUTP(a) REPx(&x, a) cin >> x.first >> x.second;
#define ENDL cout << endl;

const int INF = 2e9;
// const LL INF = 9e18;
const LL MOD = 1e9+7;

template<class T> using PRIORITY_QUEUE = priority_queue< T, V<T>, greater<T> >;
template<class T> inline bool chmin(T &a, T b){if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){if (a < b) {a = b; return true;} return false;}
template<class T> inline void debug1(V<T> A){REP(int, i, SIZE(A, int)){if (A[i] == INF) cout << "I ";else cout << A[i] << " ";}ENDL}
template<class T> inline void debug2(VV<T> A){REP(int, i, SIZE(A, int)){REP(int, j, SIZE(A[i], int)){if (A[i][j] == INF) cout << "I "; else cout << A[i][j] << " ";}ENDL}}

template<class T>
T GCD(T a, T b)
{
  while(a % b)
  {
    T r = a % b;
    a = b;
    b = r;
  }
  return b;
}

template<class T>
T LCM(T a, T b)
{
  return (a * b) / GCD(a, b);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  LL n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  if (n < m)
  {
    swap(n, m);
    swap(s, t);
  }
  LL l = LCM(n, m);
  map<LL, char> ans;
  REP(LL, i, n) ans[i*l/n+1] = s[i];
  REP(LL, i, n)
  {
    if (!ans[i*l/m+1]) continue;
    else if (ans[i*l/m+1] == t[i]) continue;
    l = -1;
    break;
  }
  cout << l << endl;

  return 0;
}
