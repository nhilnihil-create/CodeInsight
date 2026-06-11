#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)

int gcd(int A, int B) {
  int d;
  if (!A) return B;
  if (!B) return A;
  while ((d = A % B)) {
    A = B;
    B = d;
  }
  return B;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), L(N + 1), R(N + 1);
  for (auto &a : A) {
    cin >> a;
  }

  L[0] = R[N] = 0;
  for (auto i = 0; i != N; ++i) {
    L[i + 1] = gcd(L[i], A[i]);
    R[N - i - 1] = gcd(R[N - i], A[N - i - 1]);
  }

  int ans{};
  for (auto i = 0; i != N; ++i) {
    ans = max(ans, gcd(L[i], R[i + 1]));
  }

  cout << ans << endl;
}
