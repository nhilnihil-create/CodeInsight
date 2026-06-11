#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N) cin >> A[i];
  vector<int64_t> B(N);
  rep(i, N) cin >> B[i];

  vector<int64_t> C;
  int64_t answer = 0;
  int64_t debt = 0;
  rep(i, N) {
    if (A[i] < B[i]) {
      ++answer;
      debt += B[i] - A[i];
    } else {
      C.emplace_back(A[i] - B[i]);
    }
  }
  if (debt == 0) {
    cout << 0 << endl;
    return 0;
  }
  sort(C.begin(), C.end(), greater<int64_t>());

  for (auto gain : C) {
    ++answer;
    debt -= gain;
    if (debt <= 0) {
      cout << answer << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
