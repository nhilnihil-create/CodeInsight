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
/* const int MOD = 1000000007; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int N, C; 
  cin >> N >> C;

  vector<vector<int>> D(C, vector<int>(C));
  REP(i, C) REP(j, C) cin >> D[i][j];

  vector<vector<int>> vec(3, vector<int>(C, 0));
  REP(i, N) REP(j, N){
    int c;
    cin >> c;
    // pos  color
    vec[(i+j)%3][c-1]++;
  }

  int ans = INF;
  REP(a, C) REP(b, C) REP(c, C){
    if(a == b || b == c || c == a) continue;
    int ret = 0;
    REP(i, C){
      ret += D[i][a]*vec[0][i];
      ret += D[i][b]*vec[1][i];
      ret += D[i][c]*vec[2][i];
    }
    chmin(ans, ret);
  }

  cout << ans << endl;

  return 0;
}