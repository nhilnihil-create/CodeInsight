#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  int n,m,c,ans=0;
  ll test=0;
  cin>>n>>m>>c;
  int b[m];
  rep(i,m) cin>>b[i];
  int a[n][m];
  rep(i,n)rep(j,m) cin>>a[i][j];
  rep(i,n){
    rep(j,m){
      test += a[i][j]*b[j];
    }
    if(test+c > 0) ans++;
    test = 0;
  }
  cout<<ans<<endl;
}