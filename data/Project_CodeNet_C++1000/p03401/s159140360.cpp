#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 2);
  int total = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    total += abs(A[i] - A[i - 1]);
  }
  total += abs(A[N]);
  for (int i = 1; i <= N; i++) {
    int a = total - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]) + abs(A[i + 1] - A[i - 1]);
    cout << a << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */