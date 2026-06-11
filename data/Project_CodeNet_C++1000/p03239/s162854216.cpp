#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,T,i,c,t,ans=1e4;
  cin>>n>>T;
  for(i=0;i<n;i++){
    cin>>c>>t;
    if(t<=T&&c<ans) ans=c; 
  }
  if(ans<1e4) cout<<ans<<endl;
  else cout<<"TLE"<<endl;
}