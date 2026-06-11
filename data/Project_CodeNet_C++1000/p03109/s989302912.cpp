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
  string s;
  cin >> s;
  ll y=0,m=0,d=0;
  for(ll i=0;i<4;i++) {
    y*=10;
    y+=(s[i]-'0');
  }
  for(ll i=0;i<2;i++) {
    m*=10;
    m+=(s[i+5]-'0');
  }
  for(ll i=0;i<2;i++) {
    d*=10;
    d+=(s[i+8]-'0');
  }
  if(y<2019||(y==2019&&m<4)||(y==2019&&m==4&&d<=30)) {
    cout << "Heisei" << endl;
  }
  else {
    cout << "TBD" << endl;
  }
}