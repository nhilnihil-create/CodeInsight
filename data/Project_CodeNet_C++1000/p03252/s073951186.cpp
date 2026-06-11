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
  string s,t;
  cin >> s >> t;
  ll n = s.size();
  bool can = true;
  vector<ll> sc(26,-1),tc(26,-1);
  for(int i=0;i<n;i++){
    if(sc[s[i]-'a']==-1){
      sc[s[i]-'a'] = t[i];
    }
    if(tc[t[i]-'a']==-1){
      tc[t[i]-'a'] = s[i];
    }
    if(sc[s[i]-'a']!=t[i]){
      can = false;
      break;
    }
    if(tc[t[i]-'a']!=s[i]){
      can = false;
      break;
    }
  }
  if(can) cout <<"Yes\n";
  else cout <<"No\n";
}
