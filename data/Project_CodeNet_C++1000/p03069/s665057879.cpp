#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> B(N + 1);
  for (int i = 0, cnt = 0; i < N; i++) {
    if (S.at(i) == '#') cnt++;
    B.at(i + 1) = cnt;
  }
  vector<int> W(N + 1);
  for (int i = 0, cnt = 0; i < N; i++) {
    if (S.at(i) == '.') cnt++;
    W.at(i + 1) = cnt;
  }
  int ans = 1e9;
  for (int i = 0; i <= N; i++) {
    ans = min(ans, B.at(i) + (W.at(N) - W.at(i)));
  }
  cout << ans << "\n";
}