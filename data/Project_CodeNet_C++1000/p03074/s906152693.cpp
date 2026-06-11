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
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int N, K; 
  cin >> N >> K;

  string s;
  cin >> s;
  if(s.back() == '1') s += '0';
  else s += '1';

  int cnt = 1;
  vector<int> v = {0};
  if(s[0] == '0') v.emplace_back(0);
  REP(i, N){
    if(s[i] != s[i+1]){
      v.emplace_back(cnt);
      cnt = 1;
    }else cnt++;
  }

  if(v.size()%2 == 0) v.emplace_back(0);
  N = v.size();

  REP(i, N-1) v[i+1] += v[i];

  int ans = 0;
  for(int i = 1; i < N; i += 2){
    chmax(ans, v[min(N-1, i+2*K)]-v[i-1]);
  }

  cout << ans << "\n";

  return 0;
}