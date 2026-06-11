#include <bits/stdc++.h>

using namespace std;

template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }
  sort(D.begin(), D.end());
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    T[i] = abs(24 * (i % 2) - D[i]);
  }

  int res = D[0];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      res = min({res, abs(T[i] - T[j]), 24 - abs(T[i] - T[j])});
    }
  }

  cout << res << '\n';
}
