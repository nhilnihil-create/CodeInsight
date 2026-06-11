#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (a<b) swap(a,b);
  while (1) {
    if (a%b == 0) return b;
    ll r = a%b;
    a = b;
    b = r;
  }
}

ll lcm(ll a, ll b) {
  return a / gcd(a,b) * b;
}

int main() {
  ll N, M;
  string s, t;
  cin >> N >> M >> s >> t;
  ll g = gcd(N,M);
  ll L = lcm(N,M);
  bool b = true;
  
  ll n = N/g;
  ll m = M/g;
  for (ll i = 0; i < g; i++) {
    if (s[i*n] != t[i*m]) b = false;
  }
  cout << (b ? L : -1) << endl;
}