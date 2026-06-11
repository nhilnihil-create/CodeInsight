#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int K;
  cin >> K;
  vector<int64_t> A(K);
  rep(i, K) { cin >> A[i]; }

  int64_t ans_min = 2;
  int64_t ans_max = 2;
  for (int i = K - 1; i >= 0; --i) {
    // cout << ans_min << " " << ans_max << endl;
    ans_min = (ans_min + A[i] - 1) / A[i] * A[i];
    ans_max = ans_max / A[i] * A[i] + A[i] - 1;
  }
  if (ans_min > ans_max)
    cout << -1 << endl;
  else
    cout << ans_min << " " << ans_max << endl;
  return 0;
}
