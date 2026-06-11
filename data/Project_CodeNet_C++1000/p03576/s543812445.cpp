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

int N, K; 
vector<int> x, y;
int cnt(int x1, int y1, int x2, int y2){
  int ret = 0;
  REP(i, N){
    if(IN(x1, x[i], x2+1) && IN(y1, y[i], y2+1)) ret++;
  }
  return ret;
}

signed main() {
  cin >> N >> K;

  x.resize(N);
  y.resize(N);
  REP(i, N) cin >> x[i] >> y[i];

  vector<int> X(N), Y(N);
  REP(i, N){
    X[i] = x[i];
    Y[i] = y[i];
  }
  
  sort(ALL(X));
  sort(ALL(Y));

  int ans = 4*INF;
  REP(i, N) FOR(j, i+1, N) REP(k, N) FOR(l, k+1, N){
    if(cnt(X[i], Y[k], X[j], Y[l]) >= K) chmin(ans, (X[j]-X[i])*(Y[l]-Y[k]));
  }

  cout << ans << endl;

  return 0;
}