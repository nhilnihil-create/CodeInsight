#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  for (auto i = 0; i != N; ++i) {
    cin >> x[i];
  }
  for (auto i = 0; i != M; ++i) {
    cin >> y[i];
  }
  x.push_back(X);
  y.push_back(Y);

  bool pred = *max_element(ALL(x)) < *min_element(ALL(y));
  cout << (pred ? "No War" : "War") << endl;

  return 0;
}
