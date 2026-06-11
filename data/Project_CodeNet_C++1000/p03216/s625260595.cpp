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
  ll n,q;
  string s;
  cin >> n >> s >> q;
  while(q--) {
    ll k;
    cin >> k;
    ll d=0,m=0,dm=0;
    ll res=0;
    for(ll i=0;i<n;i++) {
      if(i>=k) {
        if(s[i-k]=='D') d--,dm-=m;
        if(s[i-k]=='M') m--;
      }
      if(s[i]=='D') d++;
      if(s[i]=='M') m++,dm+=d;
      if(s[i]=='C') res+=dm;
    }
    cout << res << endl;
  }
}