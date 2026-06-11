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
  int A, B, Q; 
  cin >> A >> B >> Q;

  set<int> s;
  REP(i, A){
    int a;
    cin >> a;
    s.insert(a);
  }
  set<int> t;
  REP(i, B){
    int a;
    cin >> a;
    t.insert(a);
  }

  s.insert(-INF); s.insert(INF);
  t.insert(-INF); t.insert(INF);

  while(Q--){
    int x;
    cin >> x;

    auto it1 = s.upper_bound(x);
    int a = *it1---x;
    int b = x-*it1;
    auto it2 = t.upper_bound(x);
    int c = *it2---x;
    int d = x-*it2;

    cout << min(min(max(b, d), max(a, c)), min(min(a, d)*2+max(a, d), min(b, c)*2+max(b, c))) << endl;
  }

  return 0;
}