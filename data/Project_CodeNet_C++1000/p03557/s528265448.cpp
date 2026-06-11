#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int A[100005], B[100005], C[100005];
int SUM[100005];

int main() {
  int N;
  cin >> N;
  rep(i, N) cin >> A[i]; sort(A, A+N);
  rep(i, N) cin >> B[i]; sort(B, B+N);
  rep(i, N) cin >> C[i]; sort(C, C+N);
  rep(i, N) {
    SUM[i] = lower_bound(A, A+N, B[i]) - A;
  }
  rep(i, N-1) {
    SUM[i+1] += SUM[i];
  }
  long long sum = 0;
  rep(i, N) {
    sum += (lower_bound(A, A+N, B[i]) - A) * (N - (upper_bound(C, C+N, B[i]) - C));
  }
  cout << sum << endl;
  return 0;
}

