#include <iostream>

using namespace std;

string op = "+-";

int main() {
  string S;
  cin >> S;
  int A[4];
  for (int i = 0; i != 4; ++i) A[i] = S[i] - '0';
  for (int i = 0, n = 1 << 3; i != n; ++i) {
    if (A[0] + (1 - 2 * ((i >> 0) & 1)) * A[1] +
        (1 - 2 * ((i >> 1) & 1)) * A[2] + (1 - 2 * ((i >> 2) & 1)) * A[3] == 7) {
      cout << A[0] << op[(i >> 0) & 1] << A[1] << op[(i >> 1) & 1] << A[2]
           << op[(i >> 2) & 1] << A[3] << "=7" << endl;
      break;
    }
  }
}
