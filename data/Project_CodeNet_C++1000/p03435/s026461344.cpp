#include <bits/stdc++.h>
using namespace std;

int main() {
  //A B C
  //D E F
  //G H I
  int A,B,C,D,E,F,G,H,I;
  cin >> A >> B >> C >> D >> E >> F >> G >> H >> I;
  if(A+E != B+D){
    cout << "No" << endl;
    return 0;
  }
  if(E+I != F+H){
    cout << "No" << endl;
    return 0;
  }
  if(A+I != C+G){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
