#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;
  int D,E,F;
  D=max(10*A+B,10*B+A)+C;
  E=max(10*B+C,10*C+B)+A;
  F=max(10*C+A,10*A+C)+B;
  cout << max(D,max(E,F))<< endl;
}
