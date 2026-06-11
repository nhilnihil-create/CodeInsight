#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int Left_plate = A+B;
  int Right_plate = C+D;
  if (Left_plate > Right_plate){
   cout << "Left" << endl;
  }
  else if (Left_plate < Right_plate){
   cout << "Right" << endl; 
  }
  else {
   cout << "Balanced" << endl; 
  }
}