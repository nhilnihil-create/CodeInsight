#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  ll n;
  cin >> n;
  vec d(n);
  vec c(2);
  for(ll i=0;i<n;i++) {
    cin >> d[i];
  }
  sort(d.begin(),d.end());
  ll t=24;
  for(ll i=0;i<n;i++) {
    t=min(t,d[i]-c[i&1]);
    c[i&1]=d[i];
  }
  cout << min(t,24-c[0]-c[1]) << endl;
}