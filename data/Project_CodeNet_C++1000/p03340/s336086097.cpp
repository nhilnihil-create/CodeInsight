#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long A[N+1],B[N+1],answer=0;
  A[0] = 0;
  B[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    B[i] = B[i-1]^A[i];
    A[i] += A[i-1];
  }
  for (int r = 1, l = 1; r <= N; r++) {
    while (A[r]-A[l-1] != (B[r]^B[l-1]) && l++);
    answer += r-l+1;
  }
  cout << answer;
}