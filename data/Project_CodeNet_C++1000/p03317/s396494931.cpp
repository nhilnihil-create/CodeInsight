#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  N -= K;
  ans++;
  if (N == 0) {
    cout << ans << endl;
  }
  else {
    for (int i = 0; i < 1000000; i++) {
      N -= (K - 1);
      ans++;
      if (N <= 0) {
        cout << ans << endl;
        break;
      }
    }
  }
}