#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> A, B;
ll R;

int main() {
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; ++i) cin >> A[i];
  B.resize(N);
  for (ll i = 0; i < N; ++i) cin >> B[i];
  for (ll k = 28; k >= 0; --k) {
    ll bit = 1 << k, mask = bit - 1;
    ll r = 0;
    vector<ll> a_low, b_low;
    for (ll i = 0; i < N; ++i) {
      if (A[i] & bit) (r += N) %= 2;
      a_low.push_back(A[i] & mask);
      if (B[i] & bit) (r += N) %= 2;
      b_low.push_back(B[i] & mask);
    }
    sort(b_low.begin(), b_low.end());
    for (ll x : a_low) {
      (r += b_low.end() - lower_bound(b_low.begin(), b_low.end(), bit - x)) %=
          2;
    }
    R = R * 2 + r;
  }
  cout << R << endl;
  return 0;
}
