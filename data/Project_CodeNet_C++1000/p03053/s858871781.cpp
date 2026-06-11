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

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

signed main() {
  int H, W; 
  cin >> H >> W;

  vector<string> s(H);
  REP(i, H) cin >> s[i];

  vector<vector<int>> dist(H, vector<int>(W, INF));

  queue<pair<int, int>> q;
  REP(i, H) REP(j, W){
    if(s[i][j] == '#'){
      dist[i][j] = 0;
      q.push({i, j});
    }
  }

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second; q.pop();
    REP(i, 4){
      int xx = x+dx[i];
      int yy = y+dy[i];
      if(OUT(0, xx, H)) continue;
      if(OUT(0, yy, W)) continue;
      if(dist[xx][yy] <= dist[x][y]+1) continue;
      dist[xx][yy] = dist[x][y]+1;
      q.push({xx, yy});
    }
  }

  int ans = 0;
  REP(i, H) REP(j, W){
    chmax(ans, dist[i][j]);
  }

  cout << ans << "\n";

  return 0;
}