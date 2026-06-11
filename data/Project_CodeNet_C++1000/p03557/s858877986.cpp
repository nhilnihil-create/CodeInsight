#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  int B[N];
  int C[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  
  sort(A, A+N);
  sort(B, B+N);
  sort(C, C+N);
  
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long index1 = lower_bound(A, A+N, B[i]) - A;
    long long index2 = upper_bound(C, C+N, B[i]) - C;
    ans += index1 * (N - index2);
  }

  cout << ans << endl;
}