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
  ll n,k;
  cin >> n >> k;
  vec h(n);
  for(ll i=0;i<n;i++) cin >> h[i];
  sort(h.begin(),h.end());
  ll ans=inf;
  for(ll i=0;i<n-k+1;i++) {
    ans=min(ans,h[i+k-1]-h[i]);
  }
  cout << ans << endl;
}