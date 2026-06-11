#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> v(n);
  rep(i,n)cin >> v[i].first >> v[i].second;
  sort(ALL(v));
  ll res = -1;
  res += 1ull << 63;
  rep(i,n)for(ll j = i+1;j < n;j++){
    if(j-i+1 < k)continue;
    ll width = v[j].first-v[i].first,height = 1e18;
    ll mn = min(v[i].second,v[j].second),mx = max(v[i].second,v[j].second);
    vector<ll> hei;
    for(ll g = i+1;g < j;g++)hei.push_back(v[g].second);
    sort(ALL(hei));
    rep(g,hei.size())if(g+k-2 <= hei.size())height = min(height,max(mx,hei[g+k-3])-min(height,min(mn,hei[g])));
    if(k == 2)height = min(height,mx-mn);
    res = min(res,width*height);
  }
  cout << res << endl;



  return 0;
}