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
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int N, Q; 
  cin >> N >> Q;

  string s;
  cin >> s;
  s.insert(N, "0");
  s.insert(0, "0");

  vector<char> t(Q), d(Q);
  REP(i, Q) cin >> t[i] >> d[i];

  int ok = N+1;
  int ng = 0;
  while(ok-ng > 1){
    int mid = (ok+ng)/2;

    int now = mid;
    REP(i, Q){
      if(s[now] == t[i]){
        if(d[i] == 'L') now--;
        else now++;
      }
    }
    if(now == 0) ng = mid;
    else ok = mid;
  }
  int left = ng;

  ok = 0;
  ng = N+1;
  while(ng-ok > 1){
    int mid = (ok+ng)/2;

    int now = mid;
    REP(i, Q){
      if(s[now] == t[i]){
        if(d[i] == 'L') now--;
        else now++;
      }
    }
    if(now == N+1) ng = mid;
    else ok = mid;
  }
  int right = ng;

  cout << max(0ll, right-left-1) << endl;

  return 0;
}