#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

ll inf=1e18;

int main() {
  ll a,b,q;
  cin >> a >> b >> q;
  vector<ll> s(a);
  vector<ll> t(b);
  for(ll i=0;i<a;i++) {
    cin >> s[i];
  }
  for(ll i=0;i<b;i++) {
    cin >> t[i];
  }
  vector<ll> x(q);
  for(ll i=0;i<q;i++) {
    cin >> x[i];
  }
  for(ll i=0;i<q;i++) {
    ll temp=lower_bound(s.begin(),s.end(),x[i])-s.begin();
    ll sx=-1;
    ll si=-1;
    ll tx=-1;
    ll ti=-1;
    if(temp<a) sx=s[temp];
    if(temp>0) si=s[temp-1];
    temp=lower_bound(t.begin(),t.end(),x[i])-t.begin();
    if(temp<b) tx=t[temp];
    if(temp>0) ti=t[temp-1];
    ll ans=inf;
    if(si!=-1&&ti!=-1) {
      ans=min(ans,x[i]-min(si,ti));
    }
    if(sx!=-1&&tx!=-1) {
      ans=min(ans,max(sx,tx)-x[i]);
    }
    if(sx!=-1&&ti!=-1) {
      ans=min(ans,(sx-ti)+min(sx-x[i],x[i]-ti));
    }
    if(si!=-1&&tx!=-1) {
      ans=min(ans,(tx-si)+min(tx-x[i],x[i]-si));
    }
    cout << ans << endl;
  }
}