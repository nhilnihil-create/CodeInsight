#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] -= i + 1;
  }
  sort(A.begin(), A.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(A[i] - A[N/2]);
  }
  cout << ans << "\n";
}