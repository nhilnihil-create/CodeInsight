#include <bits/stdc++.h>
using namespace std;

int main() {
  int X1,X2,Y1,Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;
  int A = X2-X1;
  int B = Y2-Y1;
  int X3 = X2-B;
  int Y3 = Y2+A;
  int X4 = X3-A;
  int Y4 = Y3-B;
  cout << X3 << " " << Y3 << " " << X4 << " " << Y4 << endl;
}
