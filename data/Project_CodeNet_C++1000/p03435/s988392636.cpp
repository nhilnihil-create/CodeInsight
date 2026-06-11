#include <bits/stdc++.h>
using namespace std;
int main(){
  int A[3][3], a1, a2, a3, b1, b2, b3;
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j) cin >> A[i][j];
  }
  for(int i=0; i<=100; ++i){
    a1 = i;
    b1 = A[0][0]-a1;
    b2 = A[0][1]-a1;
    b3 = A[0][2]-a1;
    a2 = A[1][0]-b1;
    a3 = A[2][0]-b1;
    if(A[1][1] == a2+b2 && A[1][2] == a2+b3 && A[2][1] == a3+b2 && A[2][2] == a3+b3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}