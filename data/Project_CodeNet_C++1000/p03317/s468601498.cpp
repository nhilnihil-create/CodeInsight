#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, foo;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> foo;
  }
  cout << (N - 2) / (K - 1) + 1;
  return 0;
}