#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,w,x,y,z;
  cin >> a;
  
  w = a/1000;
  x = (a/100)%10;
  y = (a/10)%10;
  z = a%10;
  
  if(x==y && y==z){
    cout << "Yes" << endl;
  }
  else if(w==x && x==y){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}