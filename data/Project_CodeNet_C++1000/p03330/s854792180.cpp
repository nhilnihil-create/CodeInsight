#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int N, C; 
  cin >> N >> C;

  vector<vector<int>> D(C, vector<int>(C));
  REP(i, C) REP(j, C) cin >> D[i][j];

  vector<vector<int>> c(N, vector<int>(N));
  REP(i, N) REP(j, N) cin >> c[i][j];


  vector<vector<int>> vec(3, vector<int>(C, 0));
  REP(i, N) REP(j, N){
    vec[(i+j)%3][c[i][j]-1]++;
  }

  int ans = INF;
  REP(i, C) REP(j, C) REP(k, C){
    if(i == j || j == k || k == i) continue;
    int ret = 0;
    REP(y, C){
      ret += vec[0][y]*D[y][i];
      ret += vec[1][y]*D[y][j];
      ret += vec[2][y]*D[y][k];
    }
    chmin(ans, ret);
  }

  cout << ans << endl;

  return 0;
}