#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  ll n,x; cin>>n>>x;
  vector<ll> v(n);
  rep(i, n) {
    ll t; cin>>t;
    v[i] = abs(x - t); 
  }
  ll gcd = __gcd(v[0], v[1]);
  for(int i = 2; i < n; i++) {
    gcd = __gcd(gcd, v[i]);
  }
  cout << gcd;
}
