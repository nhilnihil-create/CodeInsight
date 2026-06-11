#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  long long ans = 0, x, k = K % 2 ? K : K / 2;
  for (int i = k; i <= N; i += k) {
    ans++;
    x = (N - i) / K;
    ans += 3 * x * (x + 1);
  }
  cout << ans;
  return 0;
}