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
  ll a,b,c;
  cin >> a >> b >> c;
  ll d=abs(a-b),e=abs(b-c),f=abs(c-a);
  ll ans=d+e+f-max({d,e,f});
  cout << ans << endl;
}