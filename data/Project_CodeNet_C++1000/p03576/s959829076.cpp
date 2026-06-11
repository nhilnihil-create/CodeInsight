#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

signed main() {
  int N, K; 
  cin >> N >> K;

  vector<int> x(N), y(N);
  REP(i, N) cin >> x[i] >> y[i];
  
  vector<int> X = x, Y = y;
  sort(ALL(X)); sort(ALL(Y));

  auto f = [&](int x1, int y1, int x2, int y2){
    int cnt = 0;
    REP(i, N){
      if(IN(x1, x[i], x2+1) && IN(y1, y[i], y2+1)) cnt++;
    }
    if(cnt >= K) return (x2-x1)*(y2-y1);
    return 8*INF;
  };


  int ans = 8*INF;
  REP(a, N) FOR(b, a+1, N) REP(c, N) FOR(d, c+1, N){
    chmin(ans, f(X[a], Y[c], X[b], Y[d]));
  }

  cout << ans << "\n";

  return 0;
}