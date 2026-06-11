
#include<bits/stdc++.h>
using namespace std;
 
int E(int);
 
/*
  if(E(A) == 0 || E(B) == 0 || E(C) == 0 || E(D) == 0)
    exit(0);
    */
int main(){
  int A,B,C,D,L,R;
  cin >> A >> B >> C >> D;
  L = A + B;
  R = C + D;
  if(E(A) == 0 || E(B) == 0 || E(C) == 0 || E(D) == 0)
    exit(0);
  if(L > R)
    cout << "Left" << endl;
  if(L < R)
    cout << "Right" << endl;
  if(L == R)
    cout << "Balanced" << endl;
}
 
int E(int A){
  if(1 <= A & A <= 10)
    return 1;
  else return 0;
}