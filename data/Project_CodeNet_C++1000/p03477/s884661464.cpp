#include <bits/stdc++.h>
using namespace std;

int main() {
  int La,Lb,Rc,Rd;
  
  cin >> La >> Lb >> Rc >> Rd;
  
  if(La + Lb > Rc + Rd) cout << "Left";
  else if(La + Lb < Rc + Rd) cout << "Right";
  else cout << "Balanced";
}
