#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,m;
  cin>>n>>m;
  int ans=1;
  if(n==1){
    cout<<m<<endl;
    return 0;
  }
  for(int i=2;i*i<=m;i++){
    if(m%i==0){
      int a=i,b=m/i;
      if(a>=n){
        ans=max(ans,b);
      }
      if(b>=n){
        ans=max(ans,a);
      }
    }
  }
  cout<<ans<<endl;
}