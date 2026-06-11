#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, D;

  cin >> A >> B >> C >> D;

  int diff = (A + B)- (C + D);

  if (diff > 0) {
    cout << "Left" << endl;
  } else if (diff == 0) {
    cout << "Balanced" << endl;
  } else {
    cout << "Right" << endl;
  }
}