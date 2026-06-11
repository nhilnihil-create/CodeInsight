#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector A(N, 0);
  for (int i = 0, a; cin >> a; i++) A.at(i) = a - i - 1;
  sort(A.begin(), A.end());
  long m = A.at(N / 2), ans = 0;
  for (auto a : A) ans += abs(a - m);
  cout << ans << "\n";
}