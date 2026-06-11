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
  ll n,k,q,ans=1e18;
  cin >> n >> k >> q;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    vector<ll> c;
    vector<ll> use;
    for(int j=0;j<n;j++){
      if(a[i]<=a[j]){
        c.push_back(a[j]);
      }else{
        sort(c.begin(),c.end());
        ll usable = max(0ll,(ll)c.size()-k+1);
        for(int l=0;l<usable;l++){
          use.push_back(c[l]);
        }
        c.clear();
      }
    }
    sort(c.begin(),c.end());
    ll usable = max(0ll,(ll)c.size()-k+1);
    for(int l=0;l<usable;l++){
      use.push_back(c[l]);
    }
    if((ll)use.size()<q){
      continue;
    }
    sort(use.begin(),use.end());
    ans = min(ans,use[q-1]-use[0]);
  }
  cout << ans << endl;
}
