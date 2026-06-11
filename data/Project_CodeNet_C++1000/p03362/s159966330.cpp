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

vector<bool> prime(int n){
  vector<bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;
  REP(i, n){
    if(!is_prime[i]) continue;
    for(int j = 2; i*j < n; j++){
      is_prime[i*j] = false;
    }
  }
  return is_prime;
}

signed main() {
  int N; 
  cin >> N;

  auto is_prime = prime(60000);

  vector<int> ans;
  REP(i, 55555+1){
    if(is_prime[i] && i%5 == 1) ans.emplace_back(i);
  }

  REP(i, N){
    cout << ans[i]; SPBR(i, N);
  }

  return 0;
}