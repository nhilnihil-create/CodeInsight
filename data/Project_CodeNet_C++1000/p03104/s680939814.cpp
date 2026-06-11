#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A[2];
  cin >> A[0] >> A[1];
  A[0]--;
  for (int i = 0; i < 2; i++) {
    if (A[i] <= 0)
      A[i] = 0;
    else if (A[i] == 1)
      A[i] = 1;
    else if (A[i] % 4 == 0) {
      A[i] = A[i];
    } else if (A[i] % 4 == 1) {
      A[i] = 1;
    } else if (A[i] % 4 == 2) {
      A[i] = A[i] + 1;
    } else if (A[i] % 4 == 3) {
      A[i] = 0;
    }
  }
  cout << (A[0] ^ A[1]) << endl;
}