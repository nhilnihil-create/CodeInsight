#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  sort(H.begin(), H.end());
  int ans = 1e9;
  for (int i = 0; i + K - 1 < N; i++) {
    ans = min(ans, H.at(i + K - 1) - H.at(i));
  }
  cout << ans << "\n";
}