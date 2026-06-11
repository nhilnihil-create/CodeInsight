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
  ll n,cnt;
  cin >> n >> cnt;
  vec v(n);
  for(ll i=0;i<n;i++) cin >> v[i];
  ll ans=-inf;
  for(ll i=0;i<=n;i++) {
    for(ll j=0;j<=n-i;j++) {
      if(i+j>min(n,cnt)) continue;
      ll tans=0;
      priority_queue<ll,vector<ll>,greater<ll>> q;
      for(ll k=0;k<i;k++) {
        tans+=v[k];
        q.push(v[k]);
      }
      for(ll k=n-1;k>n-1-j;k--) {
        tans+=v[k];
        q.push(v[k]);
      }
      ll tcnt=0;
      while(q.size()&&tcnt<cnt-i-j) {
        ll p=q.top();
        q.pop();
        if(p<0) tans-=p;
        tcnt++;
      }
      ans=max(ans,tans);
    }
  }
  cout << ans << endl;
}