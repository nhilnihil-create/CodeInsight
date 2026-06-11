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

vector<pair<int, int>> primeFact(int n) {
  vector<pair<int, int>> res;
  for (int i = 2; i * i <= n; i++) {
    int divcnt = 0;
    if (n % i == 0) {
      do {
        divcnt++;
        n /= i;
      } while (n % i == 0);
      res.emplace_back(i, divcnt);
    }
  }
  if (n != 1)
    res.emplace_back(n, 1);
  return res;
}

signed main() {
  int N; 
  cin >> N;

  if(N < 10){
    cout << 0 << endl;
    return 0;
  }

  map<int, int> m;
  FOR(i, 2, N+1){
    auto v = primeFact(i);
    for(auto p : v){
      m[p.first] += p.second;
    }
  }

  int M = m.size();

  int cnt = 0;
  vector<int> vec(M);
  for(auto p : m){
    vec[cnt++] = p.second;
  }

  int ans = 0;
  int a = 0, b = 0, c = 0;

  REP(i, M){
    if(vec[i] >= 74) a++;
  }
  REP(i, M) REP(j, M) REP(k, M){
    if(i == j || j == k || k == i) continue;
    if(vec[i] >= 2 && vec[j] >= 4 && vec[k] >= 4) b++;
    if(vec[i] >= 4 && vec[j] >= 2 && vec[k] >= 4) b++;
    if(vec[i] >= 4 && vec[j] >= 4 && vec[k] >= 2) b++;
  }
  REP(i, M) REP(j, M){
    if(i == j) continue;
    if(vec[i] >= 2 && vec[j] >= 24) c++;
    if(vec[i] >= 4 && vec[j] >= 14) c++;
  }

  cout << a+b/6+c << endl;

  return 0;
}