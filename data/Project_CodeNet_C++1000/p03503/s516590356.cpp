#include <bits/stdc++.h>
#define rep(i,a) for ( int i=0; i<int(a); i++ )
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> F(n, vector<int>(10));
  vector<vector<int>> P(n, vector<int>(11));
  rep(i,n) rep(j,10) cin >> F[i][j];
  rep(i,n) rep(j,11) cin >> P[i][j];

  ll mx=-1e18;
  for ( int mask=1; mask<(1<<10); mask++ ) {
    ll res=0;
    for ( int i=0; i<n; i++ ) {
      int c=0;
      for ( int j=0; j<10; j++ ) {
        if ( (mask>>j&1)&&F[i][j] ) c++; 
      }
      res+=P[i][c];
    }
    mx=max(mx,res);
  }
  cout << mx << '\n';
  return 0;
}