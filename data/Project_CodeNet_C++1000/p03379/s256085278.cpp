#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), S(N);
  for (int i = 0; i != N; ++i) {
    cin >> X[i];
    S[i] = X[i];
  }
  sort(begin(S), end(S));
  auto m1 = S[N/2-1];
  auto m2 = S[N/2];
  for (auto &x: X) {
    if (x >= m2) cout << m1 << endl;
    else cout << m2 << endl;
  }
}
