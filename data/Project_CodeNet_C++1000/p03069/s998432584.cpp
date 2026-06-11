#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  string S;
  cin >> N >> S;
  vector<int> black_sum(N + 1, 0);
  for (int i = 0; i < N; i++) {
    black_sum[i + 1] = black_sum[i] + (S[i] == '#');
  }
  int ans = 10000000;
  for (int i = 0; i <= N; i++) {
    int white = N - i - (black_sum[N] - black_sum[i]);
    ans = min(ans, black_sum[i] + white);
  }
  cout << ans << endl;
  return 0;
}