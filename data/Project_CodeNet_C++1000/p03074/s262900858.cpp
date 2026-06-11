#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<pair<int, int>> A;
  int i = 0;
  while (i < N) {
    int j = i;
    while (i < N && S[i] == S[j]) i++;
    A.push_back({S[j] - '0', i - j});
  }
  int m = A.size();
  vector<int> T(m + 1);
  REP(i, m) T[i + 1] = T[i] + A[i].second;
  int ans = 0;
  REP(i, m) {
    if (A[i].first == 0) {
      int j = min(m, i + 2 * K);
      ans = max(ans, T[j] - T[i]);
    } else {
      int j = min(m, i + 2 * K + 1);
      ans = max(ans, T[j] - T[i]);
    }
  }
  cout << ans << endl;
}
