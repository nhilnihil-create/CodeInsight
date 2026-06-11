#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
using vll=vector<ll>;
int main(){
  ll n,m,b,c,e=0,i,ans=0;
  map<ll,ll> mp;
  cin>>n>>m;
  vll a(n),d(0);
  for(i=0;i<n;i++) cin>>a.at(i);
  sort(a.begin(),a.end());
  for(i=0;i<m;i++){
    cin>>b>>c;
    if(mp.count(-c)) mp.at(-c)+=b;
    else mp[-c]=b;
  }
  for(auto z:mp){
    for(i=0;i<z.second;i++){
      d.push_back(-z.first);
      e++;
      if(e==n) break;
    }
    if(e==n) break;
  }
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  for(i=0;i<min(n,e);i++) ans+=max(a.at(i),d.at(i));
  for(i=min(n,e);i<n;i++) ans+=a.at(i);
  cout<<ans<<endl;
}