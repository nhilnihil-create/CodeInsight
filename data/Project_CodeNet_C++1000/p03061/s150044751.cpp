#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), L(N + 1), R(N + 1);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  L.at(0) = 0;
  for (int i = 0; i < N; i++) L.at(i + 1) = __gcd(L.at(i), A.at(i));
  R.at(N) = 0;
  for (int i = N - 1; i >= 0; i--) R.at(i) = __gcd(R.at(i + 1), A.at(i));
  int ans = 0;
  for (int i = 0; i < N; i++) ans = max(ans, __gcd(L.at(i), R.at(i + 1)));
  cout << ans << endl;
}