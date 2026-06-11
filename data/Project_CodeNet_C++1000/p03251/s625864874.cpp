#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1e18;

int main() {
  ll n,m;
  cin >> n >> m;
  vec x(n+1),y(m+1);
  cin >> x[0] >> y[0];
  for(ll i=1;i<=n;i++) cin >> x[i];
  for(ll i=1;i<=m;i++) cin >> y[i];
  sort(x.rbegin(),x.rend());
  sort(y.begin(),y.end());
  if(x[0]<y[0]) cout << "No War" << endl;
  else cout << "War" << endl;
}