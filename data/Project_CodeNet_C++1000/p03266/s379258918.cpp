#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  long long ans;
  if (K & 1) {
    long long a = N / K;
    ans = a * a * a;
  } else {
    long long a = N / (K / 2);
    long long a1 = a / 2;
    long long a2 = a - a1;
    ans = a1 * a1 * a1 + a2 * a2 * a2;
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
