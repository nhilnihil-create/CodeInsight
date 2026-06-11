#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
map<ll,ll> a;
int main(){
  int n;cin>>n;
  rep(i,n){
    ll x;cin>>x;
    a[x]++;
  }
  ll cnt=0;
  for(auto itr=a.begin();itr!=a.end();++itr){
    ll a=itr->first;
    ll b=itr->second;
    if(a>b){
      cnt+=b;
    }else{
      cnt+=(b-a);
    }
  }
  cout<<cnt;
}