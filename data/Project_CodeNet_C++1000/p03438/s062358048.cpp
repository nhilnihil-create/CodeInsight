#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec a(n),b(n);
  ll sa=0,sb=0;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    sa+=a[i];
  }
  for(ll i=0;i<n;i++) {
    cin >> b[i];
    sb+=b[i];
  }
  if(sa>sb) {
    cout << "No" << endl;
    return 0;
  }
  ll cnt=0;
  for(ll i=0;i<n;i++) {
    if(a[i]>=b[i]) {
      cnt+=a[i]-b[i];
    }
    else {
      cnt+=(a[i]%2!=b[i]%2);
    }
  }
  if(cnt>sb-sa) cout << "No" << endl;
  else cout << "Yes" << endl;
}