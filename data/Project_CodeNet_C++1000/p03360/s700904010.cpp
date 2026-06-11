#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, K;
  cin >> A >> B >> C;
  cin >> K;
  int total;
  total = max(A, max(B, C));
  int bai = 1;
  for (int i = 1; i <= K; i++) {
    bai *= 2;
  }
  total *= (bai - 1);
  total += (A + B + C);
  cout << total << endl;
  return 0;
}
