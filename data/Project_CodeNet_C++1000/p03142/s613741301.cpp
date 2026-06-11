#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

vector<set<ll>> E(1e5+10);
vec sorted(1e5+10,-1);
ll dfs(ll n, ll num) {
  sorted[n]=num;
  for(ll t:E[n]) {
    if(sorted[t]>-1) continue;
    sorted[n]=dfs(t,sorted[n]);
  }
  return sorted[n]+1;
}

int main() {
  ll n,m;
  cin >> n >> m;
  vector<set<ll>> V(1e5+10);
  set<ll> nroot;
  for(ll i=0;i<n+m-1;i++) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    E[a].insert(b);
    V[b].insert(a);
    nroot.insert(b);
  }
  queue<ll> q;
  vec ans(n,-1);
  for(ll i=0;i<n;i++) {
    if(!nroot.count(i)) {
      dfs(i,0);
      ans[i]=0;
    }
  }
  for(ll i=0;i<n;i++) {
    if(ans[i]>-1) continue;
    for(ll t:V[i]) {
      if(ans[i]<0) ans[i]=t+1;
      else if(sorted[ans[i]-1]>sorted[t]) ans[i]=t+1;
    }
  }
  for(ll i=0;i<n;i++) {
    cout << ans[i] << endl;
  }
}