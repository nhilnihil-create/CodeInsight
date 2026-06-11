#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  int A[N], B[N], C[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(A, A+N);
  sort(B, B+N);
  sort(C, C+N);
  long dp1[N+1], dp2[N+1]; dp1[N] = dp2[N] = 0;
  for (int i = N-1; i >= 0; i--) {
    int j = lower_bound(C, C+N, B[i]+1) - C;
    dp1[i] = dp1[i+1] + N - j;
  }
  for (int i = N-1; i >= 0; i--) {
    int j = lower_bound(B, B+N, A[i]+1) - B;
    dp2[i] = dp2[i+1] + dp1[j];
  }
  cout << dp2[0] << endl;
}