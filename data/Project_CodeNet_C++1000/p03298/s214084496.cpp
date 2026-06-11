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
  int N;
  string s, t, u;
  cin >> N >> u;

  REP(i, 2*N){
    if(i < N) s += u[i];
    else t += u[i];
  }

  reverse(ALL(t));
  map<pair<string, string>, int> m1;
  map<pair<string, string>, int> m2;

  for(int i = 0; i < (1 << N); i++){
    string a, b, c, d;
    REP(j, N){
      if((i >> j)&1){
        a += s[j];
        c += t[j];
      }else{
        b += s[j];
        d += t[j];
      }
    }
    m1[make_pair(a, b)]++;
    m2[make_pair(c, d)]++;
  }

  int ans = 0;
  for(auto p : m1){
    ans += p.second*m2[p.first];
  }
  cout << ans << endl;

  return 0;
}