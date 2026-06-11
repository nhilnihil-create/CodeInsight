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
  ll n,a,b;
  cin >> n >> a >> b;
  cout << min(n*a,b) << endl;
}