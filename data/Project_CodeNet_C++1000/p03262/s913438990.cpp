#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
  if(a%b==0){
    return(b);
  }else{
    return(gcd(b,a%b));
  }
}
int main(){
  ll N,X,ans=0;
  cin>>N>>X;
  vector<ll> vec(N+1);
  vec.at(N)=X;
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  vector<ll> dist(N);
  for(ll i=0;i<N;i++){
    dist.at(i)=vec.at(i+1)-vec.at(i);
  }
  if(N==1){cout<<dist.at(0)<<endl;return 0;}
  for(ll i=0;i<N-1;i++){
    if(i==0){ans=gcd(dist.at(0),dist.at(1));}
    else{ans=gcd(dist.at(i+1),ans);}
  }
  cout<<ans<<endl;
}