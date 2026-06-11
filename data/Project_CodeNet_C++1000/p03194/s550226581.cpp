// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,p,ans=1,cnt;
  map<ll,ll> mp;
  cin >> n >> p;
  for(ll i=2;i*i<=p;i++){
    if(p%i==0){
      cnt = 0;
      while(p%i==0){
        p/=i;
        cnt++;
      }
      mp[i] = cnt;
    }
  }
  if(p!=1){
    mp[p] = 1;
  }
  for(auto i:mp){
    for(ll j=0;j<i.second/n;j++){
      ans *= i.first;
    }
  }
  cout << ans << endl;
}
