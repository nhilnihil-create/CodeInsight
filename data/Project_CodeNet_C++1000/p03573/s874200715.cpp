#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin>> A >>B >>C;
  
  //A==B
  if(A==B)
  cout<< C;  
    
  //A==C
  else if(A==C)
  cout<< B;  
  
  //B==C
  else if(B==C)
  cout<< A;  
    
}
