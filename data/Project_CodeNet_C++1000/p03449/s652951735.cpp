#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll n;
  cin>> n;
  ll a[2][n];
  rep(i,2){
    rep(j,n){
      cin>>a[i][j];
    }
}
 ll sum[n+1];
 ll plus[n+1];
 sum[0]=0;
 plus[0]=0;
 rep(i,n){
    sum[i+1]=sum[i]+a[0][i];
    plus[i+1]=plus[i]+a[1][i];
}
 ll kotae=0;
 ll ans[n];
 rep(i,n){
    ans[i]=sum[i+1]+plus[n]-plus[i];
}
 rep(i,n){
    kotae=max(kotae,ans[i]);
}
cout<<kotae<<endl;
}

