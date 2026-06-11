/*{{{*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second
#define bitcnt __builtin_popcount
#define all(x) x.begin(), x.end()
inline LL ri() {LL x; scanf("%lld", &x); return x;}
#define rep2(i, n, ...) for (int i = 0; i < (n); i ++) 
#define rep3(i, a, b, ...) for (int i = (a); i < (b); i ++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define drep2(i, n, ...) for (int i = (n) - 1; i >= 0; i --)
#define drep3(i, a, b) for (int i = (a) - 1; i >= (b); i --)
#define drep(...) GET_MACRO(__VA_ARGS__, drep3, drep2)(__VA_ARGS__)
template<typename T>inline bool smax(T&a, T b){if(a<b){a=b;return true;}return false;} 
template<typename T>inline bool smin(T&a, T b){if(a>b){a=b;return true;}return false;} 
/*}}}*/

const int maxn = 5005;
const LL inf = 1e18;

LL p[maxn][maxn], a[maxn], n, A, B, d[maxn], b[maxn];

int main() {
  rep(i, maxn) rep(j, maxn) p[i][j] = inf;
  cin >> n >> A >> B;
  rep(i, n) cin >> a[i];

  p[0][0] = 0;

  d[0] = 0; b[0] = a[0];
  rep(i, 1, n) {
    int t = lower_bound(b, b + i, a[i]) - b;
    d[i] = t;
    drep(j, i, t) {
      b[j + 1] = b[j]; 
    }
    b[t] = a[i];
  }
  //cout << d[0] << d[1] << d[2];

  rep(i, n) {
    rep(j, i + 1) {
      if (d[i] >= j) {
        //smin(p[i + 1][j], p[i][j]);
        //smin(p[i + 1][i + 1], p[i][j]);
        smin(p[i + 1][d[i] + 1], p[i][j]);
        smin(p[i + 1][j], p[i][j] + A);
      }
      else {
        smin(p[i + 1][j + 1], p[i][j] + B);
      }
      //smin(p[i + 1][i + 1], p[i][j]);
      if (j + 1 <= i) {
        smin(p[i][j + 1], p[i][j]);
      }
    }
  }

  LL res = inf;
  rep(i, n + 1) {
    smin(res, p[n][i]);
  }

  //cout << p[1][0] << endl;

  //cout << p[2][1] << endl;

  cout << res << endl;
  return 0;
}
