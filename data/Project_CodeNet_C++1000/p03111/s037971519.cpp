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

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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

int N, A, B, C; 
vector<int> l;

int dfs(int n, int a, int b, int c, int cost, bool fa, bool fb, bool fc){
  if(n == N){
    if(fa && fb && fc) return abs(A-a)+abs(B-b)+abs(C-c)+cost-30;
    return INF;
  }

  int ret = INF;
  chmin(ret, dfs(n+1, a+l[n], b, c, cost+10, true, fb, fc));
  chmin(ret, dfs(n+1, a, b+l[n], c, cost+10, fa, true, fc));
  chmin(ret, dfs(n+1, a, b, c+l[n], cost+10, fa, fb, true));
  chmin(ret, dfs(n+1, a, b, c, cost, fa, fb, fc));

  return ret;
}

signed main() {
  cin >> N >> A >> B >> C;

  l.resize(N);
  REP(i, N) cin >> l[i];

  cout << dfs(0, 0, 0, 0, 0, false, false, false) << "\n";

  return 0;
}