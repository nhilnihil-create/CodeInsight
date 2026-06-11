#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 3;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 0; i + 1 < N; i++) {
    ans += abs(A.at(i) - A.at(i + 1));
  }
  cout << ans << "\n";
}