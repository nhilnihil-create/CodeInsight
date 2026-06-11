#include<bits/stdc++.h>
using namespace std;

int main(){
  int A1,A2,A3;
  cin >> A1 >> A2 >> A3;
  int B,C,D;
  B=min(A3-A1,A3-A2),C=min(A2-A1,A2-A3),D=min(A1-A2,A1-A3);
  if(min(B,min(C,D))>=0){
    cout << min(B,min(C,D)) << endl;
  }
  else{
    cout << (-1)*min(B,min(C,D)) << endl;
  }
}