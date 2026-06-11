#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int n,m,c;
  cin >> n >> m >> c;
  
  int b[m];
  int a[n][m];
  rep(i,m) cin >> b[i];
  rep(i,n){
    rep(j,m){
      cin >> a[i][j];
    }
  }
  
  int ans = 0;
  rep(i,n){
    int sum = 0;
    rep(j,m){
      sum += a[i][j] * b[j];
    }
    sum += c;
    if(sum > 0){
      ans++;
    }//if
  }//rep
  
  cout << ans << endl;
}