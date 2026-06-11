#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = a; i < (int)(n); i++)
#define ll long long
using namespace std;

int main() {
  int H,W; cin >> H >> W;
  int d[10][10],A[H][W];
  rep(i,0,10) rep(j,0,10) cin >> d[i][j]; 
  rep(i,0,H) rep(j,0,W) cin >> A[i][j];
  rep(k,0,10) {
    rep(i,0,10) {
      rep(j,0,10) {
        d[i][j] = min(d[i][j],d[i][k]+ d[k][j]);
      }
    }
  }
  
  int ans =0;
  rep (i,0,H) rep(j,0,W) {
    if (A[i][j] == -1 || A[i][j] == 1) continue;
    else ans += d[A[i][j]][1];
  }
  cout << ans << endl;
}