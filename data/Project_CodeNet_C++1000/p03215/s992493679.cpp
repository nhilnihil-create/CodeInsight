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
  int N, K; 
  cin >> N >> K;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  vector<int> sum(N+1, 0);
  REP(i, N){
    sum[i+1] = sum[i]+A[i];
  }

  int cnt = 0;
  vector<int> vec(N*(N+1)/2);
  REP(i, N) FOR(j, i+1, N+1){
    vec[cnt++] = sum[j]-sum[i];
  }

  N = vec.size();

  int ans = 0;
  vector<bool> ng(N, false);
  RREP(i, 61){
    int cnt = 0;
    RREP(j, N){
      if(ng[j]) continue;
      if((vec[j] >> i)&1) cnt++;
    }
    if(cnt >= K){
      RREP(j, N){
        if(ng[j]) continue;
        if(!((vec[j] >> i)&1)) ng[j] = true;
      }
      ans += pow(2, i);
    }
  }

  cout << ans << endl;

  return 0;
}