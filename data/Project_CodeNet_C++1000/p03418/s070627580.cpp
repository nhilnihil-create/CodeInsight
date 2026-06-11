#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, K;
  cin >> N >> K;
  
  long long int ans = 0;
  long long int zero = 0;
  
  if (K != 0) {
    for (long long int b = K + 1; b <= N; b++) {
      ans += (N / b) * (b - K) + max(N % b - K + 1, zero);
    }
  }
  
  else ans = N * N;
  
  cout << ans << endl;
}
