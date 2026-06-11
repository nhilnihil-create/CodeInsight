#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vector<set<ll>> e(n);
  for(ll i=0;i<n-1;i++) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    e[a].insert(b);
    e[b].insert(a);
  }
  vector<ll> c(n);
  for(ll i=0;i<n;i++) {
    cin >> c[i];
  }
  sort(c.rbegin(),c.rend());
  ll count=0;
  ll root=-1;
  for(ll i=0;i<n;i++) {
    if(count<e[i].size()) {
      count =e[i].size();
      root=i;
    }
  }
  vector<ll> dis(n,-1);
  dis[root]=0;
  count=0;
  queue<ll> q;
  q.push(root);
  while(q.size()) {
    ll f=q.front();
    q.pop();
    for(ll t:e[f]) {
      if(dis[t]<0) {
        dis[t]=++count;
        q.push(t);
      }
    }
  }
  ll m=0;
  for(ll i=1;i<n;i++) {
    m+=c[i];
  }
  cout << m << endl;
  for(ll i=0;i<n;i++) {
    if(i!=0) {
      cout << " ";
    }
    cout << c[dis[i]];
  }
  cout << endl;
}