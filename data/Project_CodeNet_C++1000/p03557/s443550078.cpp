#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll N, ans{}, d{}, e{};
  cin >> N;
  vector<int> A(N), B(N), C(N);
  for (auto &a : A) cin >> a;
  for (auto &b : B) cin >> b;
  for (auto &c : C) cin >> c;
  sort(begin(A), end(A));
  sort(begin(B), end(B));
  sort(begin(C), end(C));
  for (int i = 0; i != N; ++i) {
    while (d != N && A[d] < B[i]) ++d;
    while (e != N && B[i] >= C[e]) ++e;
    ans += d * (N-e);
  }
  cout << ans << endl;
}
