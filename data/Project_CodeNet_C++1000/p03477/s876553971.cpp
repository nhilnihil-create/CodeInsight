#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int l = A+B;
  int r = C+D;
  if (l > r) cout << "Left" << endl;
  else if (l == r) cout << "Balanced" << endl;
  else cout << "Right" << endl;
}
