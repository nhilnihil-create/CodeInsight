#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const std::vector<T> &vec) {
  for (const auto &e : vec) os << e << (&e == &vec.back() ? "\n" : " ");
  return os;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  string S;
  cin >> N >> S;
  vector<int> B(N + 1, 0), W(N + 1, 0);
  for (int i = 0; i < N; i++) {
    if (S[i] == '#') B[i + 1]++;
    B[i + 1] += B[i];
  }
  for (int i = N - 1; i > -1; i--) {
    if (S[i] == '.') W[i + 1]++;
    W[i] += W[i + 1];
  }
  int res = 1 << 29;
  for (int i = 0; i < N; i++) {
    res = min(res, B[i + 1] + W[i + 1]);
  }
  cout << res - 1 << '\n';
  return 0;
}
