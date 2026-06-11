#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  rep(i, N) { cin >> A[i]; }
  rep(i, N) { cin >> B[i]; }

  int64_t largerA = 0;
  int64_t largerB = 0;
  rep(i, N) {
    if (B[i] < A[i]) {
      int64_t diff = A[i] - B[i];
      largerA += diff;
    } else {
      int64_t diff = B[i] - A[i];
      largerB += diff / 2;
    }
  }
  cout << ((largerB >= largerA) ? "Yes" : "No") << endl;
  return 0;
}
