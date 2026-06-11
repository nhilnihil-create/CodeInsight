#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  cin >> N >> H;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
  int mx = *max_element(A.begin(), A.end());
  sort(B.rbegin(), B.rend());
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (B.at(i) > mx) H -= B.at(i), cnt++;
    if (H <= 0) return cout << cnt << "\n", 0;
  }
  cout << cnt + (H + mx - 1) / mx << "\n";
}