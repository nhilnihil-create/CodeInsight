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
  string s;
  cin >> s;
  ll n=s.size();
  ll f=0;
  if(s[0]=='0'||s[n-1]=='1') f=1;
  for(ll i=0;i<n/2;i++) {
    if(s[i]!=s[n-i-2]) f=1;
  }
  if(f) {
    cout << -1 << endl;
    return 0;
  }
  vec a(n-1),b(n-1);
  ll id=0;
  for(ll i=0;i<n-1;i++) {
    a[i]=i+1;
    if(s[i]=='1') {
      while(id<i) {
        b[id]=i+1;
        id++;
      }
    }
  }
  while(id<n-1) {
    b[id++]=n;
  }
  for(ll i=0;i<n-1;i++) {
    cout << a[i] << " " << b[i] << endl;
  }
}