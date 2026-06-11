#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B , C, D;
  cin >> A >> B >> C >> D;
  int L =A+B, R =C+D;

  if (L > R) puts("Left");
  else if (L == R) puts("Balanced");
  else puts("Right");
}