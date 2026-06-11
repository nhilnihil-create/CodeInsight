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

int N, A, B, C; 
vector<int> l(10);
int dfs(int i, int cost, int a, int b, int c){
  if(i == N){
    if(a*b*c == 0) return INF;
    return cost+abs(A-a)+abs(B-b)+abs(C-c)-30;
  }

  int ret = INF;
  chmin(ret, dfs(i+1, cost,    a,      b,      c     ));
  chmin(ret, dfs(i+1, cost+10, a+l[i], b,      c     ));
  chmin(ret, dfs(i+1, cost+10, a,      b+l[i], c     ));
  chmin(ret, dfs(i+1, cost+10, a,      b,      c+l[i]));
  return ret;
}

signed main() {
  cin >> N >> A >> B >> C;

  REP(i, N) cin >> l[i];
  
  cout << dfs(0, 0, 0, 0, 0) << endl;

  return 0;
}