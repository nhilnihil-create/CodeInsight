#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, answer = 0;
  cin >> N;
  int A[N], B[N], C[N];
  for (int i = 0; i < N; A[i++] *= -1) {
    cin >> A[i];
  }
  sort(A,A+N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  sort(C,C+N);
  for (int i = 0; i < N; i++) {
    answer += (N-(upper_bound(A,A+N,-B[i])-A))*(N-(upper_bound(C,C+N,B[i])-C));
  }
  cout << answer;
}