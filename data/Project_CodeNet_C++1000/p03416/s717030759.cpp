#include <bits/stdc++.h>
using namespace std;

int digit(int C, int d);
int f(int C);

int A, B, j=0;

int main() {
  cin >> A >> B;
  for (; A<B+1; A++){
    j += f(A);
  }
  cout << j << endl;
}

int digit(int C, int d){
  int x=0, y=1;
  for(int i=0; i<d; i++){
    x = (C%(y*10) -x)/y;
    y *= 10;
  }
  return x;
}

int f(int C){
  bool i;
  if(digit(C, 1) == digit(C, 5) && digit(C, 2) == digit(C, 4)){
    i = 1;
  } else {
    i = 0;
  }
  return i;
}