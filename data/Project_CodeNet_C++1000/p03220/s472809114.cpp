#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  
  int minIndex = -1;
  double diff = pow(10, 9);
  for (int i = 0; i < N; i++) {
    auto j = T - H.at(i) * 0.006;
    auto k = abs(A - j);
    if (k < diff) {
      diff = k;
      minIndex = i + 1;
    }
  }
  
  cout << minIndex << endl;
}
