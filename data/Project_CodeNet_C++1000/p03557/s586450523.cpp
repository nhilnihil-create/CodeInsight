#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  reverse(C.begin(), C.end());
  vector<long long> AtoB(N), BtoC(N);
  int k = 0;
  for (int i = 0; i < N; i++) {
    while (k < N && B[i] < C[k]) {
      BtoC[i]++;
      k++;
    }
    if (i < N - 1) {
      BtoC[i + 1] = BtoC[i];
    }
  }
  k = 0;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    while (k < N && A[i] < B[k]) {
      AtoB[i] += BtoC[k];
      k++;
    }
    if (i < N - 1) {
      AtoB[i + 1] = AtoB[i];
    }
    ans += AtoB[i];
  }
  cout << ans << endl;
}