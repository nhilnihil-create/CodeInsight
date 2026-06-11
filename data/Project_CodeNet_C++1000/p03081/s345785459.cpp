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
  int N, Q;
  cin >> N >> Q;

  string s;
  cin >> s;

  s = 'r' + s + 'r';

  vector<char> t(Q), d(Q);
  REP(i, Q) cin >> t[i] >> d[i];

  auto f = [&](int ng, int ok, int last){
    while(abs(ok-ng) > 1){
      int mid = (ok+ng)/2;
      int now = mid;
      REP(i, Q){
        if(s[now] == t[i]){
          now = now+(d[i] == 'L'? -1: 1);
        }
      }
      if(now == last) ng = mid;
      else ok = mid;
    }
    return ok;
  };

  N = s.size()-1;
  cout << f(N, 0, N)-f(0, N, 0)+1 << "\n";

  return 0;
}