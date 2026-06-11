#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

bool is_prime(ll n) {
  for(ll i=2;i*i<=n;i++) {
    if(n%i==0) {
      return false;
    }
  }
  return n!=1;
}

int main() {
  ll n;
  cin >> n;
  vec ans(n);
  ll tmp=6;
  for(ll i=0;i<n;i++) {
    while(!is_prime(tmp)) {
      tmp+=5;
    }
    ans[i]=tmp;
    tmp+=5;
  }
  for(ll i=0;i<n;i++) {
    if(i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}