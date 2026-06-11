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
  ll n,c;
  cin >> n >> c;
  vec v(n);
  for(ll i=0;i<n;i++) {
    cin >> v[i];
  }
  ll ans=0;
  for(ll i=1;i<=min(c,n);i++) {
    for(ll j=0;j<=i;j++) {
      ll tans=0;
      priority_queue<ll,vec,greater<ll>> q;
      for(ll k=0;k<j;k++) {
        tans+=v[k];
        q.push(v[k]);
      }
      for(ll k=0;k<i-j;k++) {
        tans+=v[n-1-k];
        q.push(v[n-1-k]);
      }
      ll cnt=c-i;
      while(cnt&&q.size()&&q.top()<0) {
        tans-=q.top();
        q.pop();
        cnt--;
      }
      ans=max(ans,tans);
    }
  }
  cout << ans << endl;
}