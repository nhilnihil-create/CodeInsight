#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i] - (i + 1);
  }

  sort(B.begin(), B.end());

  long long answer = 0;

  int d_ = 0;

  d_ = N / 2;

  for (int i = 0; i < N; i++) {
    answer += abs(A[i] - (B[d_] + i + 1));
  }

  cout << answer << endl;

  return 0;

}