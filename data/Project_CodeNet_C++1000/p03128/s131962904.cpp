#include <bits/stdc++.h>

using namespace std;
using i64 = std::int_fast64_t;
using u64 = std::uint_fast64_t;

const string MIN = "-";
const vector<int> costs = {2, 5, 5, 4, 5, 6, 3, 7, 6};

void chmax(string &a, string b) {
  if (a == MIN) {
    a = b;
  } else if (a.size() < b.size()) {
    a = b;
  } else if (a.size() == b.size()) {
    if (a < b) a = b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
  vector<string> dp(N + 10, MIN);
  dp[0] = "";
  for (int i = 0; i < N + 1; i++) {
    if (dp[i] == MIN) continue;

    for (int a : A) {
      chmax(dp[i + costs[a - 1]], dp[i] + static_cast<char>('0' + a));
    }
  }
  cout << dp[N] << '\n';
  return 0;
}
