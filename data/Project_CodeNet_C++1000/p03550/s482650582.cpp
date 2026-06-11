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
  ll n,z,w;
  cin >> n >> z >> w;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  if(n==1) {
    cout << abs(a[n-1]-w) << endl;
    return 0;
  }
  cout << max(abs(a[n-1]-w),abs(a[n-1]-a[n-2])) << endl;
}