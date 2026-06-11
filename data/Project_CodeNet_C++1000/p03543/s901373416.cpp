#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,A,B,C,D;
  cin >> X ;
  A =X/1000 ;
  B =X%1000/100 ;
  C =X%100/10 ;
  D =X%10 ;
  
  
  if (A == B&& B== C && C== D) {
    cout << "Yes" << endl;
  }
  
  else if  (A == B&& B == C) {
    cout << "Yes" << endl;
  }
  else if (B == C && C== D) {
    cout << "Yes" << endl;
  }
  else{ 
  cout << "No" << endl; 
  }
}
