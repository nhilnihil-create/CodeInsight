#include <bits/stdc++.h>
using namespace std;

int64_t lucas_num(int N) {
  int64_t L0 = 2, L1 = 1, Li;
  
  if (N == 0) return L0;
  if (N == 1) return L1;
  
  for (int i = 2; i <= N; i++) {
    Li = L0 + L1;
    L0 = L1;
    L1 = Li;
  }
  return Li;
}

int main() {
  int N;
  cin >> N;
  
  cout << lucas_num(N) << endl;
}
