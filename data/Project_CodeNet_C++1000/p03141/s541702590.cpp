#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vector<pll> s(n);
  vector<ll> a(n);
  vector<ll> b(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i] >> b[i];
    s[i]=pll(a[i]+b[i],i);
  }
  sort(s.rbegin(),s.rend());
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if(i%2) {
      ans-=b[s[i].second];
    }
    else {
      ans+=a[s[i].second];
    }
  }
  cout << ans << endl;
}