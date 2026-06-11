#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

vector<char> t(2e5+10),d(2e5+10);
ll n,q;
string s;

bool front(ll f) {
  for(ll i=0;i<q;i++) {
    if(s[f]==t[i]) {
      if(d[i]=='L') {
        f--;
      }
      else {
        f++;
      }
      if(f<0) return true;
      if(f>=n) return false;
    }
  }
  return false;
}

bool back(ll f) {
  for(ll i=0;i<q;i++) {
    if(s[f]==t[i]) {
      if(d[i]=='L') {
        f--;
      }
      else {
        f++;
      }
      if(f<0) return false;
      if(f>=n) return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> q;
  cin >> s;
  for(ll i=0;i<q;i++) cin >> t[i] >> d[i];
  ll l=-1,r=n;
  ll tmp=(l+r)/2;
  ll ans=n;
  while(l+1<r) {
    if(front(tmp)) {
      l=tmp;
    }
    else {
      r=tmp;
    }
    tmp=(l+r)/2;
  }
  ans-=(l+1);
  l=-1,r=n;
  tmp=(l+r)/2;
  while(l+1<r) {
    if(back(tmp)) {
      r=tmp;
    }
    else {
      l=tmp;
    }
    tmp=(l+r)/2;
  }
  ans-=(n-r);
  cout << ans << endl;
}