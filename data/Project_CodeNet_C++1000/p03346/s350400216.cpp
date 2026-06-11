#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  map<ll,ll> c;
  for(ll i=0;i<n;i++) {
    c[a[i]]=c[a[i]-1]+1;
  }
  ll m=0;
  for(auto p:c) {
    m=max(m,(ll)p.second);
  }
  cout << n-m << endl;
}