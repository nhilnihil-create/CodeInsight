#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N + 1);
  vector<int> AS(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A[i] %= M;
    AS[i] = AS[i - 1] + A[i];
    AS[i] %= M;
  }
  map<int, int> m;
  m[0] = 1;
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += m[AS[i]];
    m[AS[i]]++;
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
