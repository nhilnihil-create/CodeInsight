#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<long long> S(N + 1, 0);
  map<long long, long long> cnt;
  cnt[0]++;
  for (int i = 0; i < N; i++) {
    S[i + 1] = S[i] + A[i];
    cnt[S[i + 1]]++;
  }

  long long ans = 0;
  for (auto c : cnt) {
    ans += c.second * (c.second - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}