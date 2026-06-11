#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;


int main() {
  ll n;
  cin >> n;
  vector<set<ll>> E(n);
  for(ll i=0;i<n-1;i++) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    E[a].insert(b);
    E[b].insert(a);
  }
  vector<ll> d1(n,-1);
  vector<ll> d2(n,-1);
  queue<ll> q;
  q.push(0);
  d1[0]=0;
  while(q.size()) {
    ll f=q.front();
    q.pop();
    for(ll t:E[f]) {
      if(d1[t]<0) {
        d1[t]=d1[f]+1;
        q.push(t);
      }
    }
  }
  ll mx=0,mi=0;
  for(ll i=0;i<n;i++) {
    if(d1[i]>mx) {
      mx=d1[i];
      mi=i;
    }
  }
  d2[mi]=0;
  q.push(mi);
  while(q.size()) {
    ll f=q.front();
    q.pop();
    for(ll t:E[f]) {
      if(d2[t]<0) {
        d2[t]=d2[f]+1;
        q.push(t);
      }
    }
  }
  mx=0;
  for(ll i=0;i<n;i++) {
    mx=max(mx,d2[i]);
  }
  if(mx%3==1) {
    cout << "Second" << endl;
  }
  else {
    cout << "First" << endl;
  }
}