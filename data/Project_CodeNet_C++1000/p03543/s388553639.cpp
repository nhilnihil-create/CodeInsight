#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  
  int a, b, c, d;
  a = N/1000;
  b = N/100 - 10*a;
  c = N/10 -10*b - 100*a ;
  d = N%10;
  
  if (a==b && b==c){
    cout << "Yes" << endl;
  } 
  else if (b==c && c==d){
    cout << "Yes"<< endl;
  }
  else{
    cout << "No" << endl;
  }

}