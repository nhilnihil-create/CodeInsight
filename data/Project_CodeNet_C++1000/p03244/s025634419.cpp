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
  ll n;
  cin >> n;
  vec v(n);
  for(ll i=0;i<n;i++) cin >> v[i];
  vector<map<ll,ll>> cnt(2);
  for(ll i=0;i<n;i++) {
    cnt[i%2][v[i]]++;
  }
  vec a(2);
  vec id(2);
  for(ll i=0;i<2;i++) {
    for(auto p:cnt[i]) {
      if(a[i]<p.second) {
        a[i]=p.second;
        id[i]=p.first;
      }
    }
  }
  if(id[0]==id[1]) {
    n-=a[0];
    a[0]=a[1]=0;
    for(ll i=0;i<2;i++) {
      for(auto p:cnt[i]) {
        if(p.first==id[i]) continue;
        a[i]=max(a[i],p.second);
      }
    }
    n-=max(a[0],a[1]);
  }
  else {
    n-=a[0]+a[1];
  }
  cout << n << endl;
}