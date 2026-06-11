#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n)cin >> a[i];
  map<ll,int> mp;
  rep(i,n)mp[a[i]]++;

  ll ans=0;
  for(auto c : mp){
    ll x=c.first;
    int y=c.second;

    if(y<x){
      ans+=y;
    }
    else{
      ans+=y-x;
    }
  }
  cout << ans <<endl;

}