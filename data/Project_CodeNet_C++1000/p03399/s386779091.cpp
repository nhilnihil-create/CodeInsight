#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D;
  if(A > B){
  E=B;
  }
  else{
  E=A;
  }
  if(C>D){
  F=D;
  }
  else{
  F=C;
  }
cout << E+F <<endl;
}
