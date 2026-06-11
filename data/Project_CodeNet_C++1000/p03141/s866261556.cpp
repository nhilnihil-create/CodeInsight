#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<pair<int, int>> C(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    C[i] = {A[i] + B[i], i};
  }
  sort(C.begin(), C.end(), greater<pair<int, int>>());

  int64_t answer = 0;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      answer += (int64_t)A[C[i].second];
    } else {
      answer -= (int64_t)B[C[i].second];
    }
  }
  cout << answer << endl;
  return 0;
}