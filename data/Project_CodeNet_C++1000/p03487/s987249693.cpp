// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  map<ll,ll> mp;
  ll n,ans=0;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  for(auto p:mp){
    ll v=p.first,c=p.second;
    if(v>c){
      ans += c;
    }else{
      ans += c-v;
    }
  }
  cout << ans << endl;
}
