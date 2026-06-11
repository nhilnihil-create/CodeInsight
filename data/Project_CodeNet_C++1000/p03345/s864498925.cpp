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
  ll a,b,c,k;
  cin >> a >> b >> c >> k;
  if(k%2) cout << b-a << endl;
  else cout << a-b << endl;
}