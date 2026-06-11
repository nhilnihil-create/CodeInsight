#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n,t;cin>>n>>t;
  int ans=1e9;
  bool f=false;
  rep(i,n){
    int a,b;cin>>a>>b;
    if(b<=t){
      ans=min(ans,a);
      f=true;
  }
  }
  if(f)cout<<ans<<endl;
    else cout<<"TLE"<<endl;
}