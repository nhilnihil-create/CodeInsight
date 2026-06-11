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
  ll n;
  cin >> n;
  vec t(n),v(n);
  for(ll i=0;i<n;i++) cin >> t[i],t[i]*=2;
  for(ll i=0;i<n;i++) cin >> v[i],v[i]*=2;
  for(ll i=0;i<n-1;i++) t[i+1]+=t[i];
  ll ct=0;
  ll cv=0;
  vec lim(8e4+10);
  for(ll i=0;i<n;i++) {
    if(i) ct--,cv--;
    while(ct<=t[i]) {
      lim[ct]=min(cv,v[i]);
      cv=lim[ct]+1;
      ct++;
    }
  }
  cv=0;
  ct--;
  double ans=0;
  while(ct) {
    cv=min(lim[ct],cv);
    ans+=cv;
    ct--;
    cv++;
  }
  ans*=1/4.0;
  cout << fixed << setprecision(10) << ans << endl;
}