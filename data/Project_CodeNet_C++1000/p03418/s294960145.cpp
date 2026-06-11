#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K; cin >> N >> K;
  long long ans = 0;
  for (int b = K+1; b <= N; b++) {
    ans += N / b * (b - K) + max(0, N % b - K + (K ? 1 : 0));
  }
  cout << ans << "\n";
}