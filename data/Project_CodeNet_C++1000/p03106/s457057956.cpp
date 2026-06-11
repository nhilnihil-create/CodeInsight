#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;

  int i = min(A, B) + 1;
  int cnt = 0;
  while (K != 0) {
    --i;
    if (A % i == 0 && B % i == 0) {
      --K;
    }
  }

  cout << i << endl;
  return 0;
}
