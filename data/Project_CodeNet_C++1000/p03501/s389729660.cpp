#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B,X,Y;
  cin >> N >> A >> B;
  X = N * A;
  Y = B;
  if (X < Y) {
    cout << X << endl;
  }
  if (X > Y) {
    cout << Y << endl;
  }
  else if (X == Y) {
    cout << X << endl;
  }
}