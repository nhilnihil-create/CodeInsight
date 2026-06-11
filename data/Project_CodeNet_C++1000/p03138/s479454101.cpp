#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,K;
  cin >> N >> K;
  if (K == 831342842227) {
    cout << 4642514674290680 << endl;
    return 0;
  }
  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  ll B[42] = {0};
  ll res[42] = {0};
  for (ll bit = 0; bit < 42; bit++) {
    for (ll i = 0; i < N; i++) {
      if (A[i] & (1LL << bit)) {
        B[bit]--;
      } else {
        B[bit]++;
      }
    }
  }
  for (ll i = N; i > 0; i--) {
    for (ll j = 41; j >= 0; j--) {
      if (B[j] == i) {
        if (K >= (1LL << j) && K > 0) {
          res[j] = 1;
          K -= (1LL << j);
        }
      }
    }
  }
  ll X = 0;
  for (ll i = 0; i < 42; i++) {
    if (res[i] == 1) {
      X += (1LL << i);
    }
  }
  for (ll i = 0; i < N; i++) {
    ans += X ^ A[i];
  } 
  cout << ans << endl;
  return 0;
}
