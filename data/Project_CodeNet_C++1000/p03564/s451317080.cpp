#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, X = 1;
  cin >> N >> K;
  
  while (X < K && N > 0) {
    X *= 2;
    N--;
  }
  cout << X + N * K << endl;
}