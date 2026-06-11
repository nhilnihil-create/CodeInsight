#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N;
  cin >> N;
  vector<long long int> A(N), S(N + 1);
  S.at(0) = 0;
  for (long long int i = 0; i < N; i++) {
    cin >> A.at(i);
    S.at(i + 1) = S.at(i) + A.at(i);
  }
  sort(S.begin(), S.end());
  long long int K = 1;
  long long int ans = 0;
  for (long long int i = 1; i <= N; i++) {
    if (S.at(i) == S.at(i - 1)) {
      ans += K;
      K++;
    }
    else K = 1;
  }
  cout << ans << endl;
}