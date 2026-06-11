#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,m;
  cin>>n>>m;
  
  map<ll,ll> ma;
  ll a,b;
  rep(i,n){
    cin>>a>>b;
    ma[a]+=b;
  }
  
  ll cnt=0,sum=0;
  for(auto itr=ma.begin();itr!=ma.end();itr++){
    if(cnt+(itr->second)>m){
      sum+=(itr->first)*(m-cnt);
      break;
    }
    else{
      sum+=(itr->first)*(itr->second);
      cnt+=(itr->second);
    }
  }
    
  cout<<sum<<endl;
 
  return 0;
}