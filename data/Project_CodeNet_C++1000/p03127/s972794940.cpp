#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
  int u,v,r;
  u=min(x,y);
  v=max(x,y);
  r=v%u;
  while(r>0){
    v=u;
    u=r;
    r=v%u;
  }
  return u;
}
int main(){
  int n,i,ans;
  cin>>n;
  vector<int> a(n);
  for(i=0;i<n;i++) cin>>a.at(i);
  ans=a.at(0);
  for(i=1;i<n;i++) ans=gcd(ans,a.at(i));
  cout<<ans<<endl;
}