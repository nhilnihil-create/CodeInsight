#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  for (auto &a: A) {
    cin >> a;
  }
  sort(begin(A), end(A));
  int d = lower_bound(begin(A), end(A), X) - begin(A);
  cout << min(d, M - d) << endl;

  return 0;
}
