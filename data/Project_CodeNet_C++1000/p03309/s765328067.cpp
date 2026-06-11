#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] -= i + 1;
  }
  sort(A, A + N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(A[i] - A[N/2]);
  }
  cout << ans;
  return 0;
}