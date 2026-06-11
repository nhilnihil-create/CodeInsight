#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
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
  int N, M;
  cin >> N >> M;

  vector<vector<int>> A(N, vector<int>(3));
  REP(i, N){
    cin >> A[i][0] >> A[i][1] >> A[i][2];
  }


  int ans = 0;
  vector<vector<int>> vec(N, vector<int>(3));
  REP(bit, (1<<3)){
    REP(i, N) REP(j, 3){
      if((bit >> j)&1) vec[i][j] = A[i][j];
      else vec[i][j] = -A[i][j];
    }
    sort(ALL(vec), [](vector<int> const &l, vector<int> const &r){
        return (l[0]+l[1]+l[2]) > (r[0]+r[1]+r[2]);
        });

    int ret = 0;
    REP(i, M){
      ret += vec[i][0]+vec[i][1]+vec[i][2];
    }
    chmax(ans, ret);
  }

  cout << ans << endl;

  return 0;
}