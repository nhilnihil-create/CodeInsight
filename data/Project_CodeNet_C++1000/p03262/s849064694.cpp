#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
  int u,v,w;
  u=min(x,y);
  v=max(x,y);
  w=v%u;
  while(w>0){
    v=u;
    u=w;
    w=v%u;
  }
  return u;
}
int main(){
  int n,x,y,z,i,ans;
  cin>>n>>y;
  vector<int> d(n);
  for(i=0;i<n;i++){
    cin>>x;
    z=abs(x-y);
    if(i==0) ans=z;
    else ans=gcd(ans,z);
  }
  cout<<ans<<endl;
}