#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  ll N, K;
  cin >> N >> K;
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  
  ll ans = 0;
  for (ll b = K+1; b <= N; b++) {
    ans += (b-K) * (N / b);
    if ((N % b) >= K)
    ans += (N % b) - K + 1;
  }
  
  cout << ans << endl;
  
}