#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int AB = A + B;
  int CD = C + D;
  if (AB > CD) cout << "Left" << endl;
  if (AB == CD) cout << "Balanced" << endl;
  if (AB < CD) cout << "Right" << endl;
}