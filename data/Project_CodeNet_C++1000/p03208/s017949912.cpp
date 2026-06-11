#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  ll n,k;cin>>n>>k;
  vector<ll> v(n);
  rep(i,n){cin>>v.at(i);}
  sort(v.begin(),v.end());
  ll ans=v.at(k-1)-v.at(0);
  ll d;
  rep(i,n-k+1){
    d=v.at(i+k-1)-v.at(i);
    ans=min(ans,d);
    if(ans==0){break;}
  }
  cout<<ans;
}