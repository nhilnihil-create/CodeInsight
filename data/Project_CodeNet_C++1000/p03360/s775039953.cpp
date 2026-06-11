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
  vec a(3);
  for(ll i=0;i<3;i++) cin >> a[i];
  sort(a.rbegin(),a.rend());
  ll k;
  cin >> k;
  while(k--) {
    a[0]*=2;
  }
  cout << a[0]+a[1]+a[2] << endl;
}