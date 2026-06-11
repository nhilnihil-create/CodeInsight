#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  
  int Left, Right;
  Left = A+B;
  Right = C+D;
  
  if (Left > Right)
    cout << "Left" << endl;
  else if (Left < Right)
    cout << "Right" << endl;
  else if (Left == Right)
    cout << "Balanced" << endl;
}