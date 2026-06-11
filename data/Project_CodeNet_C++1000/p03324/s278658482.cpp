#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  if (N == 100) {
    N++;
  }
  for (int i = 0; i < D; i++) {
    N *= 100;
  }
  cout << N << endl;
}