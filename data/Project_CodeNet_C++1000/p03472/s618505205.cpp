#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t N, H;
  cin >> N >> H;

  vector<int64_t> A(N);
  vector<int64_t> B(N);
  int64_t maxA = 0;
  rep(i, N) {
    cin >> A[i] >> B[i];
    maxA = max(maxA, A[i]);
  }
  sort(B.begin(), B.end(), greater<int64_t>());

  int64_t answer = 0;
  rep(i, N) {
    if (maxA < B[i]) {
      ++answer;
      H -= B[i];
      if (H <= 0) {
        cout << answer << endl;
        return 0;
      }
    }
  }

  answer += (H + maxA - 1) / maxA;
  cout << answer << endl;
  return 0;
}