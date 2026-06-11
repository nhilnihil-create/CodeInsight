#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll N, ans{}, d{}, e{}, f{};
  cin >> N;
  vector<ll> A(N), B(N), C(N), D(N);
  for (auto &a : A) cin >> a;
  for (auto &b : B) cin >> b;
  for (auto &c : C) cin >> c;
  sort(begin(A), end(A));
  sort(begin(B), end(B));
  sort(begin(C), end(C));
  for (int i = 0; i != N; ++i) {
    while (d != N && A[d] < B[i]) ++d;
    D[i] = d;
  }
  for (int i = 0; i != N; ++i) {
    while (e != N && B[e] < C[i]) {
      ++e;
      f += D[e-1];
    }
    ans += f;
  }
  cout << ans << endl;
}
