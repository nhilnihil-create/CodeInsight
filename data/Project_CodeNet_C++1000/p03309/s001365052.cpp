#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  vector<long> A(N);
  for (long i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i) = A.at(i) - (i + 1);
  }
  sort(A.begin(), A.end());
  long m = A.at(N / 2);
  long ans = 0;
  for (auto a : A) ans += abs(a - m);
  cout << ans << "\n";
}
