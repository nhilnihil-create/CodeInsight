#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

vector<ll>par(2e5+10);
map<ll,ll> si;
void init(ll n) {
  for(ll i=0;i<n;i++) {
    par[i]=i;
    si[i]++;
  }
}

ll root(ll x) {
  if(par[x]==x) {
    return x;
  }
  else {
    return par[x]=root(par[x]);
  }
}

ll size(ll x) {
  return si[root(x)];
}

bool same(ll x, ll y) {
  return root(x)==root(y);
}

void unite(ll x, ll y) {
  if(same(x,y)) return;
  ll temp=size(x);
  si[root(y)]+=temp;
  si[root(x)]=0;
  par[root(x)]=root(y);
}

int main() {
  ll n,m;
  cin >> n >> m;
  init(2*n);
  for(ll i=0;i<m;i++) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    unite(a,b+n);
    unite(b,a+n);
  }
  map<ll,ll> c;
  for(ll i=0;i<n;i++) {
    c[root(i)]++;
  }
  ll ans=1;
  if(c.size()==1) {
    ans=n*(n-1)/2;
  }
  else {
    for(auto p:c) ans*=p.second;
  }
  ans-=m;
  cout << ans << endl;
}