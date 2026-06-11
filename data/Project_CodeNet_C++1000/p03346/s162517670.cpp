#include <bits/stdc++.h>

using namespace std;
using i32 = std::int_fast32_t;
using u64 = std::uint_fast64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i32 N;
  cin >> N;
  vector<i32> cnt(N + 1, 0);
  for (i32 i = 0; i < N; i++) {
    i32 p;
    cin >> p;
    cnt[p] = cnt[p - 1] + 1;
  }
  i32 res = 0;
  for (i32 i = 1; i < N + 1; i++) {
    res = max(res, cnt[i]);
  }
  cout << N - res << '\n';
  return 0;
}
