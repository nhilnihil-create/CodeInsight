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
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  map<ll,ll> mp;
  for(int i=0;i<4;i++){
    ll tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  if(mp[1]&mp[9]&mp[7]&mp[4]) cout << "YES\n";
  else cout <<"NO\n";
}
