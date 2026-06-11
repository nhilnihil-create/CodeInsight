#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,k;
  cin >> n >> k;
  vector<int> po,ne;
  rep(i,n){
    int x;cin >> x;
    x >= 0 ? po.push_back(x) : ne.push_back(-x);
  }
  reverse(ALL(ne));
  ll res = (1ll << 60);
  for(int i = 1;i < k;i++){
    if(i > po.size())break;
    ll neg = k-i;
    if(neg > ne.size())continue;
    res = min(res,min(po[i-1],ne[neg-1])*2ll+max(po[i-1],ne[neg-1]));
  }
  if(po.size() >= k)res = min(res,po[k-1]*1ll);
  if(ne.size() >= k)res = min(res,ne[k-1]*1ll);
  cout << res << endl;





  

  return 0;
}