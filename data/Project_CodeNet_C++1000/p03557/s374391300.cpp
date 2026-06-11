#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i{}; i < N; ++i) cin >> A[i];
  for (int i{}; i < N; ++i) cin >> B[i];
  for (int i{}; i < N; ++i) cin >> C[i];
  sort(A.begin(), A.end());
//  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  ll ans{};
  for (int j{}; j < N; ++j) {
    int i = lower_bound(A.begin(), A.end(), B[j]) - A.begin();
//    if (!i) continue;
    int k = upper_bound(C.begin(), C.end(), B[j]) - C.begin();
    ans += static_cast<ll>(i) * (N - k);
  }

  cout << ans << endl;
  return 0;
}
