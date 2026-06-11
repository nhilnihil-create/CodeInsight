#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int a = A + B , b = C + D;
  
  if (a > b) {
    cout << "Left" << endl;
  }
  else if (a < b) {
    cout << "Right" << endl;
  }
  else {
    cout << "Balanced" << endl;
  }
}
