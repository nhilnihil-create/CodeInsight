#include <bits/stdc++.h>
using namespace std;

int main() {
  long long D, G;
  cin >> D >> G;

  vector<int> P(D), C(D);

  for (int i = 0; i < D; i++) {
    cin >> P[i] >> C[i];
  }

  long long ans = 10000;
  for (int tmp = 0; tmp < (1 << D); tmp++) {
    bitset<10> s(tmp);
    long long sum = 0;
    long long count = 0;
    for (int i = 0; i < D; i++) {
      if (s.test(i)) {
        sum += P[i] * 100 * (i + 1) + C[i];
        count += P[i];
      }
    }
    if (sum >= G) {
      ans = min(ans, count);
    } else {
      for (int j = D - 1; j >= 0; j--) {
        if (s.test(j) == false) {
          for (int k = 0; k < P[j]; k++) {
            sum += (j + 1) * 100;
            count++;
            if (sum >= G) {
              ans = min(ans, count);
              break;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}