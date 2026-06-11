#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin>>n;
  int t[n],v[n];
  rep(i,n) cin>>t[i];
  rep(i,n) cin>>v[i];
  int s[n+1];
  s[0]=0;
  rep(i,n){
    s[i+1]=s[i]+t[i];
  }
  double ans[2*s[n]+1];
  rep(i,2*s[n]+1){
    ans[i]=min(i/2.0,s[n]-i/2.0);
  }
  rep(i,2*s[n]+1){
    rep(j,n){
      if(i/2.0<s[j]){
        ans[i]=min(ans[i],v[j]+s[j]-i/2.0);
      }
      else if(i/2.0>s[j+1]){
        ans[i]=min(ans[i],v[j]-s[j+1]+i/2.0);
      }
      else{
        ans[i]=min(ans[i],v[j]+0.0);
      }
    }
  }
  double res=0;
  rep(i,2*s[n]){
    res+=(ans[i]+ans[i+1])/4.0;
  }
  cout<<fixed<<setprecision(5);
  cout<<res<<endl;
}