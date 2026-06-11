#include<bits/stdc++.h>
using namespace std;

int main(){
  int x1,y1,x2,y2,x3,y3,x4,y4,rx,ry;
  cin >> x1 >> y1 >> x2 >> y2;
  rx = x2 - x1;
  ry = y2 - y1;
  
  x3 = x2 - ry;
  y3 = y2 + rx;
  x4 = x1 - ry;
  y4 = y1 + rx;

  cout << x3 <<" "<< y3 <<" "<< x4 <<" "<< y4 << endl;
  return 0;
}