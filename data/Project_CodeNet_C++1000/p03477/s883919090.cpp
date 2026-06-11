#include <bits/stdc++.h>
using namespace std;

int main() {
  int A = 0, B = 0, C = 0, D = 0;
  cin >> A >> B >> C >> D;
  
  if(A + B > C + D) {
    cout << "Left" << endl;
  }else if(A + B == C + D) {
    cout << "Balanced" << endl;
  }else{
    cout << "Right" << endl;
  }
}
