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
  int N, M;
  cin >> N >> M;

  vector<int> A(M);
  REP(i, M) cin >> A[i];
  sort(ALL(A), greater<>());

  vector<int> cnt = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  // i本だけ使って作れる最大の桁数
  vector<int> dp(N+1, -INF);
  dp[0] = 0;
  REP(i, N) for(int j : A){
    if(i+cnt[j] <= N) chmax(dp[i+cnt[j]], dp[i]+1);
  }

  while(N != 0) for(int j : A){
    if(N-cnt[j] >= 0) if(dp[N] == dp[N-cnt[j]]+1){
      N -= cnt[j];
      cout << j;
      break;
    }
  }
  cout << "\n";

  return 0;
}