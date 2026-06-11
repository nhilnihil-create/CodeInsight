#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
using namespace std;
typedef long long int ll;
ll gcd(ll a, ll b) {
  if (a < b)
    return gcd(b, a); 
  if (b == 0)
    return a;
  return gcd(b, a % b);
}


ll ceil(ll a, ll b) {
  return (a + b - 1) /b;
}

int main() {
  ll T;
  cin >> T;
  while (T--) {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A < B) { cout << "No" << endl; continue; }
    if (D < B) { cout << "No" << endl; continue; }
    if (C >= B) { cout << "Yes" << endl; continue; }
    ll g = gcd(B, D);
    ll a = A % g;
    ll m = a + ceil(C + 1 - a, g) * g;
    if (C < m && m < B && m < D) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
