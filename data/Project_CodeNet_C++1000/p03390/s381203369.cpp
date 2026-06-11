#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int Q; cin >> Q;
  while (Q--) {
    ll A, B; cin >> A >> B;
    if (A > B) swap(A, B);

    ll ans;
    if (A == B) {
      ans = 2 * A - 2;
    } else if (A + 1 == B) {
      ans = 2 * A - 2;
    } else {
      ll C = sqrt(A * B);
      if (C * C == A * B) --C;
      if (C * (C + 1) < A * B) {
        ans = 2 * C - 1;
      } else {
        ans = 2 * C - 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
