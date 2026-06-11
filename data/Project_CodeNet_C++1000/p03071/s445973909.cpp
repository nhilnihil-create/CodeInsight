


#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  int X=0;
  for(int i=0;i<2;i++){
  if(A>B){
    X =X+A;
    A--;
  }
  else{
    X =X+B;
    B--;
  }
  }
  cout << X << endl;
}














