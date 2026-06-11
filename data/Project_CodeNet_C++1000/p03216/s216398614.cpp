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
  ll n,q;
  string s;
  cin >> n >> s >> q;
  vector<ll> k(q);
  for(int i=0;i<q;i++){
    cin >> k[i];
  }
  for(int j=0;j<q;j++){
    ll ans = 0,dc=0,mc=0,dms=0;
    for(int i=0;i<n;i++){
      if(s[i]=='D'){
        dc++;
      }else if(s[i]=='M'){
        mc++;
        dms += dc;
      }else if(s[i]=='C'){
        ans += dms;
      }
      ll idx = i-k[j]+1;
      if(idx>=0){
        if(s[idx]=='D'){
          dc--;
          dms -= mc;
        }else if(s[idx]=='M'){
          mc--;
        }
      }
    }
    cout << ans << endl;
  }
}
