#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<long long> A(N), B(N), C(N);
  for(size_t i = 0; i < N; i++) cin >> A[i];
  for(size_t i = 0; i < N; i++) cin >> B[i];
  for(size_t i = 0; i < N; i++) cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  long long ans = 0;
  for(size_t i = 0; i < N; i++) {
    long long upper = distance(A.begin(), lower_bound(A.begin(), A.end(), B.at(i)));
    long long bottom = N - distance(C.begin(), upper_bound(C.begin(), C.end(), B.at(i)));
    ans += upper * bottom;
  }

  cout << ans << endl;

  return 0;
}