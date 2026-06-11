#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t N;
  cin >> N;
  vector<int> Y(N);
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
    Y.at(i) = X.at(i);
  }
  sort(X.begin(), X.end());
  for (int i = 0; i < N; i++) {
    bool ok = false;
    if (Y.at(i) < X.at(N / 2)) {
      ok = true;
    }
    if (ok) {
      cout << X.at((N / 2)) << endl;
    }
    else {
      cout << X.at((N / 2) - 1) << endl;
    }
  }
}