#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  ll n;
  cin >> n;
  vec t(n+1),v(n+1,0);
  for(ll i=0;i<n;i++) cin >> t[i],t[i]*=2;
  for(ll i=0;i<n;i++) cin >> v[i],v[i]*=2;
  ll to=0;
  ll id=0;
  vec z(8e4+10,0);
  for(ll i=0;i<n;i++) {
    to+=t[i];
    z[id]=min(z[id],v[i]);
    for(id++;id<=to;id++) z[id]=min(z[id-1]+1,v[i]);
    id--;
  }
  ll mv=0;
  double ans=0;
  for(ll i=id-1;i;i--) {
    mv=min(z[i],mv+1);
    ans+=double(mv);
  }
  ans/=4.0;
  printf("%.9f", ans);
}