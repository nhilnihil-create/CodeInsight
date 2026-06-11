#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] -= i + 1;
  }
  sort(begin(A), end(A));
  auto ans = accumulate(begin(A), end(A), 0ll, [&](long long x, int y) {
    return x + abs(y - A[(N - 1) / 2]);
  });
  cout << ans << endl;
}
