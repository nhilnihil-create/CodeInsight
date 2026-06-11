#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


int main(void) {
  ll N;
  cin >> N;
  vector<ll> v;
  ll i;
  map<ll, ll> mp;
  
  for(i=0; i<N; i++) {
    ll a;
    cin >> a;
    
    mp[a]++;
    if(mp[a]==1) v.push_back(a);
  }
  sort(v.begin(), v.end());
  
  
  
  ll ans=0;
  for(i=(ll)v.size()-1; i>=0; i--) {
    ll t=1;
    while(v[i]>=t) t<<=1;
    
    ll itr=lower_bound(v.begin(), v.end(), t-v[i])-v.begin();
    if(v[itr]+v[i]==t) {
      if(v[itr]==v[i]) {
        ans+=mp[v[i]]/2;
      }else {
        ans+=min(mp[v[itr]], mp[v[i]]);
        mp[v[itr]]-=min(mp[v[itr]], mp[v[i]]);
      }
    }
  }
  
  pt(ans);
  
}
