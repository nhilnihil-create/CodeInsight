#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int64_t> ACC(N + 1, 0);
  for (int i = 0; i < N; i++) {
    ACC[i + 1] = ACC[i] + A[i];
  }
  vector<int64_t> B;
  for (int i = 0; i < N + 1; i++) {
    for (int j = i + 1; j < N + 1; j++) {
      B.emplace_back(ACC[j] - ACC[i]);
    }
  }
  vector<int64_t> sets;
  for (int64_t bit = 60; bit > -1; bit--) {
    vector<int64_t> cands;
    if (sets.empty()) {
      for (int64_t b : B) {
        if ((b >> bit) & 1) cands.emplace_back(b);
      }
    } else {
      for (int64_t b : sets) {
        if ((b >> bit) & 1) cands.emplace_back(b);
      }
    }
    if ((int)cands.size() >= K) sets = cands;
  }
  if (sets.empty()) {
    cout << 0 << '\n';
  } else {
    int64_t res = sets[0];
    for (int64_t b : sets) {
      res &= b;
    }
    cout << res << '\n';
  }
  return 0;
}
