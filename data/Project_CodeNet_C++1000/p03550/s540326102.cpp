#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N, Z, W;
  cin >> N >> Z >> W;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int score0 = abs(A[N - 1] - W);
  int score1 = 0;
  if (N > 1) {
    score1 = abs(A[N - 2] - A[N - 1]);
  }
  cout << max(score0, score1) << endl;
  return 0;
}
