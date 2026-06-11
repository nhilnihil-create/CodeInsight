#include <bits/stdc++.h>
using namespace std;

/*
(R + X) / 2 = G
R + X = 2 * G
X = 2 * G - R
*/

int main() {
  int inNumR = 0;
  int inNumG = 0;
  cin >> inNumR >> inNumG;
  cout << 2 * inNumG - inNumR << endl;
}