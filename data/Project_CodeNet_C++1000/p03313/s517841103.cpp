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
  vec a(1<<n),r(1<<n),m(1<<n);
  for(ll i=0;i<(1<<n);i++) cin >> a[i];
  for(ll i=0;i<(1<<n);i++) {
    for(ll j=i;j<(1<<n);j=(j+1)|i) {
      r[j]=max(r[j],a[i]+m[j]);
      m[j]=max(m[j],a[i]);
    }
  }
  for(ll i=1;i<1<<n;i++) {
    r[i]=max(r[i],r[i-1]);
    cout << r[i] << endl;
  }
}