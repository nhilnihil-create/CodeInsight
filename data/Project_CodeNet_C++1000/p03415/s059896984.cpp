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
  vector<string> s(3);
  for(ll i=0;i<3;i++) cin >> s[i];
  for(ll i=0;i<3;i++) cout << s[i][i];
  cout << endl;
}