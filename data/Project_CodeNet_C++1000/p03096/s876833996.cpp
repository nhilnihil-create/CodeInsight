#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll MOD = 1e9 + 7;
  int N; cin >> N;
  vector<int> C(N, 0);
  for (int i = 0; i < N; i++) {
    int c; cin >> c; c--;
    C[i] = c;
  }

  vector<ll> ans(N, 0);
  vector<ll> pos(2e5 + 10, -1);

  for (int i = 0; i < N; i++) {
    int c = C[i];
    if (pos[c] != -1 && C[i] != C[i - 1]) {
      int p = pos[c];
      ans[i] = (ans[i - 1] + ans[p] + 1) % MOD;
    } else if (i > 0) {
      ans[i] = ans[i - 1];
    }
    pos[c] = i;
  }
  cout << (ans[N - 1] + 1) % MOD << '\n';

  return 0;
}