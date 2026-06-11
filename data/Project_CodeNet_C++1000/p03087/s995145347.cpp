#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<int> l(Q), r(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<int> C(N);
  C[N - 1] = 0;
  for (int i = N - 1; 0 < i; --i) {
    C[i - 1] = C[i] + (0 == S.compare(i - 1, 2, "AC"));
  }
  for (int i = 0; i < Q; ++i) {
    cout << C[l[i] - 1] - C[r[i] - 1] << endl;
  }
  return 0;
}
