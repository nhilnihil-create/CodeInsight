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
  ll n,a,b;
  cin >> n >> a >> b;
  ll f=0,s=0,t=0;
  for(ll i=0;i<n;i++) {
    ll p;
    cin >> p;
    if(p<=a) f++;
    else if(p<=b) s++;
    else t++;
  }
  cout << min({f,s,t}) << endl;
}