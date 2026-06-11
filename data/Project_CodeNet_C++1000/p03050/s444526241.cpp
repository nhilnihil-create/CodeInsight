#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;
  vector<ll> a;
  for(ll i = 1; i*i <=n; i++) {
    if(i*i==n) a.push_back(i);
    else if(n%i==0) {
      a.push_back(i);
      a.push_back(n/i);
    }
  }
  ll ans = 0;
  for(auto p : a) {
    p--;
    if(p!=0&&n/p==n%p) ans += p;
  }
  cout << ans << endl;
  return 0;
}