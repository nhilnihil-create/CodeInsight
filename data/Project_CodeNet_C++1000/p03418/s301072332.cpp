#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  if (K == 0) { cout << (long long)N * N << endl; return 0; }
  long long ans = 0;
  for (int b = K + 1; b <= N; b++) {
    ans += ((N + 1) / b) * (b - K) + max((N + 1) % b - K, 0);
  }
  cout << ans << endl;
}