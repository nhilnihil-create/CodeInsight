#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll a[N];
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll m = 1e9; ll M = -1e9;
  ll p, q;
  for (ll i = 0; i < N; i++) {
    if (m > a[i]) p = i;
    if (M < a[i]) q = i;
    m = min(a[i],m); M = max(a[i],M);
  }
  if (m >= 0) {
    cout << N-1 << endl;
    for (ll i = 0; i < N-1; i++) {
      cout << i+1 << " " << i+2 << endl;
    }
  } else if (M <= 0) {
    cout << N-1 << endl;
    for (ll i = 0; i < N-1; i++) {
      cout << N-i << " " << N-i-1 << endl;
    }
  }
  else if (abs(m) <= abs(M)) {
    cout << 2*N-1 << endl;
    for (ll i = 0; i < N; i++) {
      cout << q+1 << " " << i+1 << endl;
    }
    for (ll i = 0; i < N-1; i++) {
      cout << i+1 << " " << i+2 << endl;
    }
  } else {
    cout << 2*N-1 << endl;
    for (ll i = 0; i < N; i++) {
      cout << p+1 << " " << i+1 << endl;
    }
    for (ll i = 0; i < N-1; i++) {
      cout << N-i << " " << N-i-1 << endl;
    }
  }
}