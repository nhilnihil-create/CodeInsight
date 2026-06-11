#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll res=1;
  ll ans=1;
  for(ll i=0;i<n;i++) {
    if(a[i]%2==0) res*=2;
    ans*=3;
  }
  cout << ans-res << endl;
}