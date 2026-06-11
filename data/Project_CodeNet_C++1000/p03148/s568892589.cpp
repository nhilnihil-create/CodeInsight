#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<pll> a(n);
  for(ll i=0;i<n;i++) {
    ll t,d;
    cin >> t >> d;
    a[i]={d,t};
  }
  sort(a.rbegin(),a.rend());
  ll ans=0;
  ll tans=0;
  map<ll,ll> kind;
  priority_queue<pll,vector<pll>,greater<pll>> q;
  for(ll i=0;i<k;i++) {
    tans+=a[i].first;
    kind[a[i].second]++;
    q.push({a[i].first,a[i].second});
  }
  ans=tans+kind.size()*kind.size();
  ll cur=k;
  for(ll i=kind.size()+1;i<=k;i++) {
    ll f=1;
    while(q.size()) {
      ll t=q.top().second;
      ll d=q.top().first;
      q.pop();
      if(kind[t]>1) {
        kind[t]--;
        tans-=d;
        f=0;
        break;
      }
    }
    if(f) break;
    f=1;
    for(;cur<n;cur++) {
      ll t=a[cur].second;
      ll d=a[cur].first;
      if(kind[t]==0) {
        kind[t]++;
        tans+=d;
        cur++;
        f=0;
        break;
      }
    }
    if(f) break;
    ans=max(ans,tans+i*i);
  }
  cout << ans << endl;
}