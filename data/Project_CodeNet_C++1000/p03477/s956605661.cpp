#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int AB = A + B;
  int CD = C + D;
  
  if(AB == CD){
    cout << "Balanced" << endl;
  }else if(AB > CD){
    cout << "Left" << endl;
  }else{
    cout << "Right" << endl;
  }

  return 0;
}
