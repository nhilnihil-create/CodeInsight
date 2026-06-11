#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  cin >> N >> H;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  int mx = *max_element(A.begin(), A.end());
  sort(B.rbegin(), B.rend());
  int ans = 0;
  for (auto b : B) {
    if (b > mx) H -= b, ans++;
    else break;
    if (H <= 0) return cout << ans << "\n", 0;
  }
  cout << ans + (H + mx - 1) / mx << "\n";
}