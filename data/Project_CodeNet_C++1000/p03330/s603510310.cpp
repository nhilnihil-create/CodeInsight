#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c)), g(n, vector<int>(n));
  REP(i, c) REP(j, c) cin >> d[i][j];
  REP(i, n) REP(j, n) cin >> g[i][j], g[i][j]--;

  vector<vector<int>> cost(3, vector<int>(c, 0));
  REP(k, c) REP(i, n) REP(j, n) cost[(i+j)%3][k] += d[g[i][j]][k];

  int ans = INF;
  int a[3];
  for(a[0] = 0; a[0] < c; a[0]++){
    for(a[1] = 0; a[1] < c; a[1]++){
      if(a[0] == a[1]) continue;
      for(a[2] = 0; a[2] < c; a[2]++){
        if(a[0] == a[2] || a[1] == a[2]) continue;
        int t = 0;
        REP(i, 3) t += cost[i][a[i]];
        chmin(ans, t);
      }
    }
  }
  cout << ans << endl;
  return 0;
}