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

using namespace std;


signed main() {
  string s;
  int gx, gy;
  cin >> s >> gx >> gy;

  int N = s.size();
  vector<int> x, y;
  int cnt = 0;
  int direct = 1;
  REP(i, N){
    if(i == N-1 && s[i] == 'F') cnt++;
    if(s[i] == 'T' || i == N-1){
      if(direct%2) x.push_back(cnt);
      else y.push_back(cnt);
      direct++;
      cnt = 0;
    }else{
      cnt++;
    }
  }

  vector<vector<bool>> xdp(x.size()+1, vector<bool>(2*N, false));
  xdp[0][N] = true;
  REP(i, x.size()){
    REP(j, 2*N){
      if(xdp[i][j]){
        xdp[i+1][j+x[i]] = true;
        if(i != 0) xdp[i+1][j-x[i]] = true;
      }
    }
  }

  vector<vector<bool>> ydp(y.size()+1, vector<bool>(2*N, false));
  ydp[0][N] = true;
  REP(i, y.size()){
    REP(j, 2*N){
      if(ydp[i][j]){
        ydp[i+1][j+y[i]] = true;
        ydp[i+1][j-y[i]] = true;
      }
    }
  }

  if(xdp[x.size()][N+gx] && ydp[y.size()][N+gy]) Yes;
  else No;

  return 0;
}