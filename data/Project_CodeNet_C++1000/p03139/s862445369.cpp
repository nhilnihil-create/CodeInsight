#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int maxval = min(A, B);
  int minval = 0;
  if (N < A + B) {
    minval = A+B-N;
  }
  cout << maxval << " " << minval << endl;

  return 0;
}
