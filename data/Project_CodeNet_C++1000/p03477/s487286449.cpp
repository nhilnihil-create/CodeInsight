#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int L1, L2, R1, R2;
  cin >> L1 >> L2 >> R1 >> R2;
  
  if(L1 + L2 < R1 + R2){
    cout << "Right" << endl;
  }
  else if(L1 + L2 == R1 + R2){
    cout << "Balanced" << endl;
  }
  else{
  cout << "Left" << endl;
  }
}