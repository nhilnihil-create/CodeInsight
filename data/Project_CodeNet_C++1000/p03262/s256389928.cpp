#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd (ll a, ll b) {
  return a % b ? gcd(b, a% b) : b;
}
int main() {
  int N;
  ll X;
  cin >> N >> X;
  
  ll x[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    x[i] -= X;
    x[i] = abs(x[i]);
  }  

  ll ans = x[0];
  for (int i = 1; i < N; i++) {
    if (ans >= x[i]) {
      ans = gcd(ans, x[i]);
    } else {
      ans = gcd(x[i], ans);
    }
  }
  
  cout << ans << endl;
}