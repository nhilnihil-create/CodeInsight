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
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    auto itA = lower_bound(A.begin(), A.end(), B[i]);
    auto itC = upper_bound(C.begin(), C.end(), B[i]);
    long long indexA = itA - A.begin();
    long long indexC = C.end() - itC;
    ans += indexA * indexC;
  }
  cout << ans << endl;
}