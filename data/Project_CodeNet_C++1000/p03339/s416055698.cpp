#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> W(N), E(N);
  W.at(0) = 0;
  for (int i = 1; i < N; i++) {
    if (S.at(i - 1) == 'W') W.at(i) = W.at(i - 1) + 1;
    else W.at(i) = W.at(i - 1);
  }
  E.at(N - 1) = 0;
  for (int i = N - 2; i >= 0; i--) {
    if (S.at(i + 1) == 'E') E.at(i) = E.at(i + 1) + 1;
    else E.at(i) = E.at(i + 1);
  }
  int ans = N;
  for (int i = 0; i < N; i++) {
    ans = min(ans, W.at(i) + E.at(i));
  }
  cout << ans << endl;
}