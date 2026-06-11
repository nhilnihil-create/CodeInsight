#include<bits/stdc++.h>
using namespace std;
int main() {
  int64_t n,m,a,b,i,ans=0,c=0;
  map<int64_t,int64_t> mp;
  cin>>n>>m;
  for(i=0;i<n;i++){
    cin>>a>>b;
    if(mp.count(a)) mp.at(a)+=b;
    else mp[a]=b;
  }
  for(auto z:mp){
    ans+=z.first*z.second;
    c+=z.second;
    if(c>=m){
      ans-=z.first*(c-m);
      break;
    }
  }
  cout<<ans<<endl;
}