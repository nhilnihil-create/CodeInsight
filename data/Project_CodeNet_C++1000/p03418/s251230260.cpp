#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  if (!K) return cout << (long) N * N << "\n", 0;
  long ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i <= K) continue;
    ans += (long) N / i * (i - K);
    ans += max(0, N % i - K + 1);
  }
  cout << ans << "\n";
}