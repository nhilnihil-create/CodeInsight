#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
  lint N, P; cin >> N >> P;
  if (N == 1) {
    cout << P << endl;
    return 0;
  }

  lint a = 2;
  lint ans = 1;
  while (pow(a, N) <= P) {
    if (P % lint(pow(a, N)) == 0) {
      P /= pow(a, N);
      ans *= a;
    } else {
      a++;
    }
  }
  cout << ans << endl;
}
