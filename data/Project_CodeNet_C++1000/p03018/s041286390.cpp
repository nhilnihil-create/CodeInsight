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
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  string s, t;
  cin >> s;

  int N = s.size();
  REP(i, N){
    if(i != N-1 && s[i] == 'B' && s[i+1] == 'C') t += "D", i++;
    else t += s[i];
  }

  int M = t.size();
  int cnt = 0, ans = 0;
  REP(i, M){
    if(t[i] == 'A') cnt++;
    else if(t[i] == 'D'){
      ans += cnt;
    }else{
      cnt = 0;
    }
  }

  cout << ans << endl;

  return 0;
}
