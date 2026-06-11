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
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll cnt=0;
  for(ll i=1;i<n;i++) {
    if(a[i]==a[i-1]) {
      cnt++;
      i++;
    }
  }
  cout << cnt << endl;
}