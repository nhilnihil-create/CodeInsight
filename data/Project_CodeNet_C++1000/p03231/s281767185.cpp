#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template <typename T>
T gcd(T a, T b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}

int main() {
  ll N, M;
  cin >> N >> M;
  string s, t;
  cin >> s >> t;

  ll L = lcm(M, N);

  map<ll, char> m;
  int sc = L / N;
  for (int j = 0; j < N; j++) m[sc * j] = s[j];

  int tc = L / M;
  bool ok = true;
  for (int j = 0; j < M; j++) {
    if (m.count(tc * j) == 0) continue;
    if (m[tc * j] != t[j]) ok = false;
  }

  ll ans = -1;
  if (ok) ans = L;
  cout << ans << endl;
}
