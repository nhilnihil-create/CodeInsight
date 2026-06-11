#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  A.insert(A.begin(), 0);
  A.insert(A.end(), 0);

  int sum = 0;
  for (int i = 0; i < N + 1; i++) sum += abs(A[i] - A[i + 1]);

  for (int i = 1; i < N + 1; i++) {
    int ans = 0;
    ans = sum + abs(A[i + 1] - A[i - 1]) - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]);
    cout << ans << endl;
  }
}