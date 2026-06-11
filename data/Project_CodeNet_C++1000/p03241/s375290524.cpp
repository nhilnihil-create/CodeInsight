#include <bits/stdc++.h>
using namespace std;

vector<long> div(long n) {
  vector<long> v;
  for (long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) v.push_back(n / i);
    }
  }
  sort(begin(v), end(v));
  return v;
}

int main() {
  int N, M;
  cin >> N >> M;
  auto V = div(M);
  int ans = 1;
  for (auto v : V) {
    if ((long) v * N > M) break;
    ans = v;
  }
  cout << ans << "\n";
}