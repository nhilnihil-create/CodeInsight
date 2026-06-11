#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m,a,i,s=0,ans=0;
  cin>>n>>m;
  map<int64_t,int64_t> c;
  c[0]=1;
  for(i=0;i<n;i++){
    cin>>a;
    s=(s+a)%m;
    if(c.count(s)) c.at(s)++;
    else c[s]=1;
  }
  for(auto z:c) ans+=z.second*(z.second-1)/2;
  cout<<ans<<endl;
}