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
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if(abs(a-c)<=d) cout << "Yes" << endl;
  else if(abs(a-b)<=d&&abs(b-c)<=d) cout << "Yes" << endl;
  else cout << "No" << endl;
}