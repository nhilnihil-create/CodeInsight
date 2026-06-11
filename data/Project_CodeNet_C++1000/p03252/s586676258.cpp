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
  string s,t;
  cin >> s >> t;
  ll n=s.size();
  map<ll,ll> cs,ct;
  for(ll i=0;i<n;i++) {
    if(cs[s[i]]) {
      if(cs[s[i]]!=t[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    cs[s[i]]=t[i];
    if(ct[t[i]]) {
      if(ct[t[i]]!=s[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    ct[t[i]]=s[i];
  }
  cout << "Yes" << endl;
}