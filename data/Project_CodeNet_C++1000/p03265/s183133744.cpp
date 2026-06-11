#include <bits/stdc++.h>
using namespace std;

int main(){
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int e1_x= x2- x1;
  int e1_y= y2- y1;
  int e2_x= -e1_y;
  int e2_y=  e1_x;

  int x3= x2+ e2_x;
  int y3= y2+ e2_y;
  int x4= x1+ e2_x;
  int y4= y1+ e2_y;

  cout << x3 <<" "<< y3 <<" "<< x4 <<" "<< y4 << endl;
}