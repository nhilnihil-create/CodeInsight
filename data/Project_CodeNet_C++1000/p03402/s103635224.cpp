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
  int a, b;
  cin >> a >> b;
  int k = 50;
  vector<string> grid(2*k);
  REP(i, k) grid[i] = string(2*k, '#');
  REP(i, k) grid[i+k] = string(2*k, '.');

  int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
  int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
  int count = 0;
  REP(i, k-1) REP(j, 2*k){
    if(count == a-1) continue;
    bool ok = true;
    REP(n, 8){
      int jd = j+dx[n];
      int id = i+dy[n];
      if(id < 0 || jd < 0 || jd >= 2*k) continue;
      if(grid[id][jd] == '.') ok = false;
    }
    if(!ok) continue;
    grid[i][j] = '.';
    count++;
  }

  count = 0;
  FOR(i, k+1, 2*k) REP(j, 2*k){
    if(count == b-1) continue;
    bool ok = true;
    REP(n, 8){
      int jd = j+dx[n];
      int id = i+dy[n];
      if(2*k <= id || jd < 0 || jd >= 2*k) continue;
      if(grid[id][jd] == '#') ok = false;
    }
    if(!ok) continue;
    grid[i][j] = '#';
    count++;
  }
  printf("%d %d\n", 2*k, 2*k);
  REP(i, 2*k) cout << grid[i] << endl;

  return 0;
}