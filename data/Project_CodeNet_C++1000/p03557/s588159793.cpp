#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
vector<int> A, B, C;

int main() {
  cin >> N;

  A.resize(N);
  B.resize(N);
  C.resize(N);

  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    cin >> B[i];
  for (int i = 0; i < N; i++)
    cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  long long int res = 0;
  for (int i = 0; i < N; i++) {
    auto A_low_iter = lower_bound(A.cbegin(), A.cend(), B[i]);
    auto C_low_iter = upper_bound(C.cbegin(), C.cend(), B[i]);

    res += static_cast<long long int>(distance(A.cbegin(), A_low_iter)) *
           static_cast<long long int>(distance(C_low_iter, C.cend()));
  }
  cout << res << endl;

  return 0;
}
