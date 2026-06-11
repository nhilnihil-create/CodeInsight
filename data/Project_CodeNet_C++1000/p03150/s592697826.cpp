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
  string s;
  cin >> s;
  ll n = s.size();
  bool can = false;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      string t="";
      for(int k=0;k<n;k++){
        if(i==k) k = j;
        t += s[k];
      }
      if(t == "keyence"){
        can = true;
      }
    }
  }
  if(can) cout <<"YES\n";
  else cout <<"NO\n";
}
