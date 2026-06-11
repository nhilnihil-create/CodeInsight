#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  auto f = [&](int a, int b) {
    vector<string> T = S;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        T[i][j] = S[(i + a) % N][(j + b) % N];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (T[i][j] != T[j][i]) return false;
      }
    }
    return true;
  };
  int res = 0;
  for (int b = 0; b < N; b++) {
    if (f(0, b)) res += N;
  }
  cout << res << '\n';
  return 0;
}
