#include <bits/stdc++.h>
using namespace std;

int main() {
  double a;
  cin>>a;
  
  int x,y,z;
  
  x=a/100;
  
  y=(a-100*x)/10;
  
  z=a-100*x-10*y;
  
  cout<<x+y+z<<endl;
  
  
  
}
