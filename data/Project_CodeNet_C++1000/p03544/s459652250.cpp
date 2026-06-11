#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  int64_t Li = 2;
  int64_t Lj = 1;
  int64_t Lk = 0;
  if (N == 1) { cout << 1; return 0; }
  for (int i = 2; i <= N; i++) {
    Lk = Li + Lj;
    Li = Lj;
    Lj = Lk;
  }
  cout << Lk;
}