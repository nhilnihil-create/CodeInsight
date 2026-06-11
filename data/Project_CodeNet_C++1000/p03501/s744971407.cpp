#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, N, x, fineT, fine;

  cin >> N >> A >> B;

  fineT = N * A;
  fine = B;

  x = min(fineT, fine);

  cout << x << endl;
}
