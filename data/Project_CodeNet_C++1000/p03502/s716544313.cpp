#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, X, f = 0;
  cin >> N;
  X = N;

  while (true) {
    f += N % 10;
    N = N / 10;
    if (N == 0) break;
  }
  
  if (X % f == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
   
}