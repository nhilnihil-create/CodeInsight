#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X;
  cin >> N >> X;
  int x[N + 1];
  x[0] = X;
  for (int i = 1; i < N + 1; i++) {
    cin >> x[i];
  }
  int prefix[N];
  for (int i = 0; i < N; i++) {
    prefix[i] = x[i + 1] - x[i];
  }
  int D = prefix[0];
  for (int i = 1; i < N; i++) {
    D = gcd(D, prefix[i]);
  }
  cout << abs(D);
  return 0;
}