#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b,q;
  cin >> a >> b >> q;
  ll s[a],t[b];
  for(ll i=0;i<a;i++)cin >> s[i];
  for(ll i=0;i<b;i++)cin >> t[i];

  ll c[a],d[b];

  for(ll i=0;i<a;i++){
    ll e=lower_bound(t,t+b,s[i])-t;
    if(e==b)c[i]=abs(s[i]-t[b-1]);
    else if(e==0)c[i]=abs(s[i]-t[0]);
    else c[i]=min(abs(s[i]-t[e]),abs(s[i]-t[e-1]));
  }

  for(ll i=0;i<b;i++){
    ll e=lower_bound(s,s+a,t[i])-s;
    if(e==b)d[i]=abs(t[i]-s[a-1]);
    else if(e==0)d[i]=abs(t[i]-s[0]);
    else d[i]=min(abs(t[i]-s[e]),abs(t[i]-s[e-1]));
  }

  vector<ll> v;

  for(ll i=0;i<q;i++){
    ll x;
    cin >> x;
    ll m=inf;
    ll e=lower_bound(s,s+a,x)-s;
    if(e==a){
      ll n=abs(x-s[a-1]);
      n+=c[a-1];
      m=min(m,n);
    }
    else if(e==0){
      m=min(m,abs(x-s[0])+c[0]);
    }
    else{
      m=min(m,abs(x-s[e])+c[e]);
      m=min(m,abs(x-s[e-1])+c[e-1]);
    }

    e=lower_bound(t,t+b,x)-t;
    if(e==b){
      ll n=abs(x-t[b-1]);
      n+=d[b-1];
      m=min(m,n);
    }
    else if(e==0){
      m=min(m,abs(x-t[0])+d[0]);
    }
    else{
      m=min(m,abs(x-t[e])+d[e]);
      m=min(m,abs(x-t[e-1])+d[e-1]);
    }
    v.push_back(m);

  }

  for(ll i=0;i<q;i++)cout << v[i] << endl;

}