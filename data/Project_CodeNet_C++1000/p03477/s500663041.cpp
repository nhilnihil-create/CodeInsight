#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int L = A + B, R = C + D;
  cout << ((L > R) ? "Left" :
          ((L < R) ? "Right" : "Balanced")) << endl;
  return 0;
}
