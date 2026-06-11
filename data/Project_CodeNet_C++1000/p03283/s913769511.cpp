#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,m,q;
  cin>>n>>m>>q;
  
  ll A[n+1][n+1];
  rep(i,n+1){
    rep(j,n+1) A[i][j]=0;
  }
  
  ll l,r;
  rep(i,m){
    cin>>l>>r;
    A[l][r]++;
  }
  
  ll s[n+2][n+2];
  rep(i,n+2){
    rep(j,n+2) s[i][j]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+A[i][j];
    }
  }
  
  ll a,b;
  rep(i,q){
    cin>>a>>b;
    cout<<s[b+1][b+1]-s[a][b+1]-s[b+1][a]+s[a][a]<<endl;
  }

  return 0;
}