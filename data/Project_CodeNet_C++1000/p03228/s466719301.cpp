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
  ll a,b,k;
  cin >> a >> b >> k;
  for(ll i=0;i<k;i++) {
    if(i%2) {
      b-=b%2;
      a+=b/2;
      b/=2;
    }
    else {
      a-=a%2;
      b+=a/2;
      a/=2;
    }
  }
  cout << a << " " << b << endl;
}