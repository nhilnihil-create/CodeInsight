#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> V(K);
  for (int i = 1; i <= N; i++) {
    V.at(i % K)++;
  }
  long ans = 0;
  for (int i = 0; i < K; i++) {
    int a = i;
    int b = (K - a) % K;
    int c = (K - a) % K;
    if ((b + c) % K == 0) {
      ans += (long) V.at(a) * V.at(b) *V.at(c);
    }
  }
  cout << ans << "\n";
}