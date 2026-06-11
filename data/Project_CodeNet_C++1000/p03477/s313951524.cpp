#include <bits/stdc++.h>
using namespace std;

int main() {
  int A , B , C , D;
  cin >> A >> B >> C >> D;
  
  int a = A + B;
  int c = C + D;
  
  if (a < c) {
    cout << "Right" << endl;
  }
  else if (a == c) {
    cout << "Balanced" << endl;
  }
  else if (a > c) {
    cout << "Left" << endl;
  }
}
