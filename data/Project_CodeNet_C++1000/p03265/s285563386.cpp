#include<bits/stdc++.h>
using namespace std;

int main(){
  int x1,x2,y1,y2;
  int xDl,yDl;
  int x3,x4,y3,y4;
  
  cin >> x1 >> y1 >> x2 >> y2;
  
  xDl = x2 - x1;
  yDl = y2 - y1;
  
  x3 = x2 + (-1)*yDl;
  y3 = y2 + xDl;
  x4 = x3 + (-1)*xDl;
  y4 = y3 + (-1)*yDl;

  cout << x3 << " ";
  cout << y3 << " ";
  cout << x4 << " ";
  cout << y4 << " ";
}