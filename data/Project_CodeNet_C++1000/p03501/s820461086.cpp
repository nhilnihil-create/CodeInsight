#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int p = A * N;
  if (B < p) p = B;
  cout << p << endl;
  return 0;
}
