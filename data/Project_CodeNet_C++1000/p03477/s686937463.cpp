#include <bits/stdc++.h>
using namespace std;

int main() {

  int A = 0;
  int B = 0;
  int C = 0;
  int D = 0;

  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;

  if ((A + B) > (C + D)) {
    cout << "Left" << endl;
  } else if ((A + B) == (C + D)) {
    cout << "Balanced" << endl;
  } else if ((A + B) < (C + D)) {
    cout << "Right" << endl;
  }
}

