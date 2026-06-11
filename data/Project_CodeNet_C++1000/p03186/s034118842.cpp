#include<bits/stdc++.h>
using namespace std;
int main()
{
  int A,B,C;
  int D;
  int E,F;
  int G;
  
  cin >> A >> B >> C;
  G=C;
  E = B+A+1;
  if(C<E)F=C;
  else{
  D= C-E;
  F= C-D;
  }
  F = (F+B);
  cout << F << endl;
}