#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  rep(i, N) cin >> A[i];
  int maxK = N * (N + 1) / 2;
  vector<int64_t> B;
  rep(i, N) {
    int64_t sum = 0;
    for (int j = i; j < N; ++j) {
      sum += A[j];
      B.emplace_back(sum);
    }
  }

  int64_t answer = 0;
  for (int i = 39; i >= 0; --i) {
    int count = 0;
    rep(j, maxK) {
      if ((B[j] & answer) == answer && (B[j] & (1LL << i))) ++count;
    }
    if (K <= count) answer |= (1LL << i);
  }
  cout << answer << endl;
  return 0;
}
