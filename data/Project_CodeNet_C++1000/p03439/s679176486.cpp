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
  ll l=0,r=n-1;
  cout << l << endl;
  string s0,sn;
  cin >> s0;
  if(s0=="Vacant") return 0;
  cout << r << endl;
  cin >> sn;
  if(sn=="Vacant") return 0;
  while(1) {
    ll m=(l+r)/2;
    cout << m << endl;
    string s;
    cin >> s;
    if(s=="Vacant") return 0;
    if(m%2==l%2) {
      if(s==s0) l=m;
      else {
        r=m;
        sn=s;
      }
    }
    else {
      if(s==s0) {
        r=m;
        sn=s;
      }
      else {
        l=m;
        s0=s;
      }
    }
  }
}