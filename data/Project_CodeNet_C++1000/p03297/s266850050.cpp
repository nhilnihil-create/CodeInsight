#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll m, ll n) {
  if (n == 0) return m;
  else return gcd(n, m % n);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  ll A[T], B[T], C[T], D[T];
  for (int i = 0; i < T; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  for (int i = 0; i < T; i++) {
    if (B[i] > A[i] || B[i] > D[i]) {
      cout << "No\n";
    } else if(C[i] >= B[i] - 1) {
      cout << "Yes\n";
    } else {
      ll g = gcd(B[i], D[i]);
      ll l = A[i] - B[i] + 1;
      ll r = A[i] - C[i] - 1;
      ll q = 0;
      ll k = (r - q + g) / g - (l - q + g - 1) / g;
      if (k > 0) {
        cout << "No\n";
      } else {
        cout << "Yes\n";
      }
    }
  }
  return 0;
}