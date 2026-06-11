#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  int C=0;
  cin>>A;
  B=A;
  C+=A%10;
  while(A>=10){
    A/=10;
    C+=A%10;
  }
  if(C==1&&B>1){
    cout<<10;
  }
  else{
    cout<<C;
  }
  return 0;
}