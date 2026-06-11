#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int n;
  cin >> n;
  ll u[n][11];
  ll f[n][10];
  rep(i,n){
    rep(j,10){
      cin >> f[i][j];
    }
  }
  rep(i,n){
    rep(j,11){
      cin >> u[i][j];
    }
  }
  ll ans=-1000000000000000;
  rep(i,(1<<10)){
    if(i==0)continue;
    ll a=0;
    rep(j,n){
      int m=0;
      rep(l,10){
        if(i&(1<<l)){
          m+=f[j][l];
        }
      }
      a=a+u[j][m];
    }
    ans=max(ans,a);
  }
  cout << ans << endl;
}
