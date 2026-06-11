#include <bits/stdc++.h>
using namespace std;

int main() {
  char A, B, C;
  cin >>A >>B >>C;

  if(A=='1'){
    A='9';
  }
  else if(A=='9'){
    A='1';
  }

  if(B=='1'){
    B='9';
  }
  else if(B=='9'){
    B='1';
  }

    if(C=='1'){
    C='9';
  }
  else if(C=='9'){
    C='1';
  }

  cout << A << B << C << endl;

return 0;  
}