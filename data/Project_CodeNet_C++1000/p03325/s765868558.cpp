#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  ll n;cin>>n;
  ll ans=0;
  vector<ll> v(n);
  rep(i,n){
    cin>>v.at(i);
  }
  rep(i,n){
    ll c=0;
    while(true){
      if(v.at(i)%2==1){
        break;
      }
      c++;
      v.at(i)/=2;
    }
    ans+=c;
  }
  cout<<ans;
}