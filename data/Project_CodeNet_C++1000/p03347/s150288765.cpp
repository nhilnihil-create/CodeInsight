#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N) { cin >> A[i]; }
  if (A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }

  int64_t answer = 0;
  for (int i = N - 1; i > 0; --i) {
    if (A[i - 1] >= A[i]) {
      answer += A[i];
    } else if (A[i] - A[i - 1] >= 2) {
      cout << -1 << endl;
      return 0;
    } else {
      ++answer;
    }
  }
  cout << answer << endl;
  return 0;
}