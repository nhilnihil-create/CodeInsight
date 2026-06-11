#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  map<int64_t, int64_t> mp;
  mp[0]++;
  int64_t res = 0, x = 0;
  for (int i = 0; i < N; i++) {
    x += A[i];
    res += mp[x]++;
  }
  cout << res << '\n';
  return 0;
}
