#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll n;
  cin>>n;
  map<ll,ll> p;
  rep(i,n){
    ll a;
    cin>>a;
    p[a]++;
  }
  ll ans=0;
  for(auto x:p){
    if(x.second>=x.first){
      ans+=x.second-x.first;
    }
    else{
      ans+=x.second;
    }
  }
  cout<<ans<<endl;
}


