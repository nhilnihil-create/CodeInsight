#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A,B,C,D;
  A=N/1000;
  B=N%1000/100;
  C=N%100/10;
  D=N%10;
  
  
  if((A==B&&B==C)||(B==C&&C==D)){
  cout<<"Yes"<<endl;
  }
  else {
   cout << "No"<< endl;
  }
}