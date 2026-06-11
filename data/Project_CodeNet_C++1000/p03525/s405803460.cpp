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
  int N; 
  cin >> N;

  map<int, int> m;
  REP(i, N){
    int d;
    cin >> d;
    m[d]++;
  }

  int ans = 12;
  if(m[0] >= 1)  ans = 0;
  if(m[12] >= 2) ans = 0;
  for(auto p : m) if(p.second >= 3) ans = 0;

  vector<int> vec = {0};
  bool right = true;
  for(auto p : m){
    if(p.second == 2){
      vec.emplace_back(p.first);
      vec.emplace_back(24-p.first);
    }else if(p.second == 1){
      if(right) vec.emplace_back(p.first);
      else vec.emplace_back(24-p.first);
      right = !right;
    }
  }

  sort(ALL(vec));

  REP(i, vec.size()-1){
    chmin(ans, vec[i+1]-vec[i]);
  }

  cout << ans << endl;

  return 0;
}