#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n = 3;
  vector<vector<int>> c(n,vector<int>(n));
  rep(i,n){
    rep(j,n){
      cin >> c[i][j];
    }
  }
  
  bool ok = true;
  rep(i,n-1){
    if(c[i][1]-c[i][0] != c[i+1][1]-c[i+1][0]) ok = false;
    if(c[i][2]-c[i][1] != c[i+1][2]-c[i+1][1]) ok = false;
    if(c[1][i]-c[0][i] != c[1][i+1]-c[0][i+1]) ok = false;
    if(c[i][2]-c[i][1] != c[i+1][2]-c[i+1][1]) ok = false;
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
