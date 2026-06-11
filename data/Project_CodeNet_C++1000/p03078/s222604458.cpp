#include <bits/stdc++.h>

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
  int X, Y, Z, K; 
  cin >> X >> Y >> Z >> K;

  vector<int> A(X);
  REP(i, X) cin >> A[i];

  vector<int> B(Y);
  REP(i, Y) cin >> B[i];

  vector<int> C(Z);
  REP(i, Z) cin >> C[i];

  vector<int> D;
  REP(i, X) REP(j, Y){
    D.emplace_back(A[i]+B[j]);
  }
  sort(ALL(D), greater<>());

  vector<int> ans;
  REP(i, min(K, (int)D.size())) REP(j, Z){
    ans.emplace_back(D[i]+C[j]);
  }
  sort(ALL(ans), greater<>());

  REP(i, K){
    cout << ans[i] << endl;
  }

  return 0;
}