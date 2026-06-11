#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, turn = -1;
  cin >> N;
  int64_t L1 = 2, L2 = 1, lucas = 1;
  for (int i = 1; i < N; i++) {
    turn *= -1;
    if (turn == 1) {
      L1 += L2;
      lucas = L1;
    }
    else {
      L2 += L1;
      lucas = L2;
    }
  }
  cout << lucas << endl;
}