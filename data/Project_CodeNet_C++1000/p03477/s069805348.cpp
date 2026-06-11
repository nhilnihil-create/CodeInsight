#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  1 <= A,B,C,D <= 10;
  cin >> A >> B >> C >> D;
  if (A+B > C+D) {
    cout << "Left" << endl;
  } else if (A+B == C+D) {
    cout << "Balanced" << endl;
  } else {
    cout << "Right" << endl;
  }
}
