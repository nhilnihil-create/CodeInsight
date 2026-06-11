#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  vector<int> X(N + 1);
  for (int i = 1; i < N + 1; i++) {
    X.at(i) = X.at(i - 1) + A.at(i - 1);
  }
  vector<int> Y(N + 1);
  for (int i = 1; i < N + 1; i++) {
    Y.at(i) = Y.at(i - 1) + B.at(i - 1);
  }
  int ans = 0;
  for (int i = 1; i < N + 1; i++) {
    ans = max(ans, X.at(i) + (Y.at(N) - Y.at(i - 1)));
  }
  cout << ans << "\n";
}