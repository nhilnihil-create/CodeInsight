#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll  = long long;
using v   = vector<int>;
using vv  = vector<v>;
using P   = pair<ll,ll>;
using vp  = vector<P>;
using vvp = vector<vp>;

int main(){
    ll n,m;
    cin>>n>>m;
  
  vp ab(n);
  rep(i,n)cin>>ab[i].first>>ab[i].second;
  
  sort(ab.begin(), ab.end());
  
  ll count = 0;
  ll ans = 0;
  rep(i,n){
    if(ab[i].second>m){
      ans += m*ab[i].first;
      break;
    }
    else{
      ans += ab[i].second * ab[i].first;
      m -= ab[i].second;
    }
  }
    cout << ans << endl;
    
    return 0;
}