#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

int t[3][30];
int d[30][30];

int main()
{
  int n,c;
  cin >> n >> c;
  REP(i,c) REP(j,c) cin >> d[i][j];
  REP(i,n) REP(j,n){
    int x;
    cin >> x;
    t[(i+j)%3][x-1]++;
  }
  int ans = 2e9;
  REP(i,c) REP(j,c){
    if(i!=j){
      REP(k,c){
        if(k!=i && k!=j){
          int tt = 0;
          REP(l,c) tt += d[l][i] * t[0][l];
          REP(l,c) tt += d[l][j] * t[1][l];
          REP(l,c) tt += d[l][k] * t[2][l];
          ans = min(ans, tt);
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
