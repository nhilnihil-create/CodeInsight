#include <bits/stdc++.h>
using namespace std;

int main() {
  long long K, A, B;
  cin >> K >> A >> B;

  if (B - A <= 2 || K < A - 1) {
    cout << K + 1 << endl;
    return 0;
  } else {
    long long ans = A;
    long long cnt = K - A + 1;
    if (cnt % 2 == 1) ans++, cnt--;
    ans += (cnt / 2) * (B - A);
    cout << ans << endl;
  }
}
