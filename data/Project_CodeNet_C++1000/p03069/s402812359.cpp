#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> W(N + 1), B(N + 1);
  W.at(N) = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (S.at(i) == '.') W.at(i) = W.at(i + 1) + 1;
    else W.at(i) = W.at(i + 1);
  }
  B.at(0) = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '#') B.at(i + 1) = B.at(i) + 1;
    else B.at(i + 1) = B.at(i);
  }
  int ans = 1000000;
  for (int i = 0; i <= N; i++) {
    ans = min(ans, W.at(i) + B.at(i));
  }
  cout << ans << endl;
}