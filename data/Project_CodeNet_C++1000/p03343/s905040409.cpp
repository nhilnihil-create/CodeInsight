#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=2e3+10;
vec a(N);
ll c[N];
ll n,k,q;

ll check(ll l, ll r) {
  ll p=-1,s=0;
  for(ll i=0;i<=n;i++) {
    if(a[i]<c[l]) {
      ll t=0;
      for(ll j=p+1;j<i;j++) {
        if(a[j]<=c[r]) t++;
      }
      s+=max(0LL,min(t,i-p-k));
      p=i;
    }
  }
  return s>=q;
}

int main() {
  cin >> n >> k >> q;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    c[i]=a[i];
  }
  sort(c,c+n);
  ll ans=inf;
  for(ll i=0,j=0;i<n;i++) {
    while(j<n&&!check(i,j)) j++;
    if(j<n) ans=min(ans,c[j]-c[i]); 
  }
  cout << ans << endl;
}