#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  ll n,m; cin>>n>>m;
  vector<pair<ll, ll>> v(n);
  
  rep(i,n){
   cin>>v.at(i).first>>v.at(i).second;
  }
  sort(v.begin(),v.end());
  ll i=0,ans=0;
  while(true){
    
    if(m>v.at(i).second){
      m-=v.at(i).second;
      ans+=v.at(i).first*v.at(i).second;
      i++;
    }
    else{
      ans+=m*v.at(i).first;
      m=0;
    }
    if(m==0){break;}
  
  }
  cout<<ans;
}