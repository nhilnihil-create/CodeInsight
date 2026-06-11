#include <bits/stdc++.h>
using ll = long long;

int main() {
  ll N;
  std::cin >> N;
  std::vector<ll> A(N);
  for (int i = 0; i < N; i++) std::cin >> A[i];
  std::vector<ll> cumsum(N + 1);
  cumsum[0] = 0;
  for (int i = 0; i < N; i++) {
    cumsum[i + 1] = cumsum[i] + A[i];
  }
  std::unordered_map<ll, ll> counter;
  for (auto&& v : cumsum) {
    counter[v]++;
  }
  ll res{0};
  for (auto&& p : counter) {
    ll k {p.second};
    res += (k * (k - 1)) / 2;
  }
  std::cout << res << std::endl;
  return 0;
}