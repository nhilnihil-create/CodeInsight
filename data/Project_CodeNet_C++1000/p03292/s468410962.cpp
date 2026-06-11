#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int K = max(A, B);
  K = max(K, C);
  int J = min(A, B);
  J = min(J, C);
  cout << K - J << endl;
}
  