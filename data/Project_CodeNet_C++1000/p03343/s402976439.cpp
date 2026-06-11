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
  ll n,k,Q;
  cin >> n >> k >> Q;
  vec a(n);
  vector<pll> b(n);
  vec al(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    b[i]={a[i],i};
  }
  sort(b.begin(),b.end());
  ll ans=inf;
  for(ll i=0;i<n;i++) {
    ll id=b[i].second;
    priority_queue<ll,vec,greater<ll>> q;
    vec c;
    for(ll j=0;j<n;j++) {
      if(al[j]) {
        while(q.size()) q.pop();
      }
      else {
        q.push(a[j]);
        if(q.size()==k) {
          c.push_back(q.top());
          q.pop();
        }
      }
    }
    al[id]=1;
    if(c.size()<Q) break;
    sort(c.begin(),c.end());
    ans=min(ans,c[Q-1]-c[0]);
  }
  cout << ans << endl;
}