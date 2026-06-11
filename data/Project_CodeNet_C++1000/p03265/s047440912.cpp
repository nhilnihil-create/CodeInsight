#include <bits/stdc++.h>
#include <math.h>
using namespace std;


int main() {
  int x1 , y1 , x2 , y2 ;
  cin >> x1 >> y1 >> x2 >> y2 ;
  
  int a=abs(x1-x2);
  int b=abs(y1-y2);
  
  int x3 , y3 , x4 , y4 ;
  if(x1<=x2&&y1<=y2){
    x3=x2-b;
    y3=y2+a;
    x4=x3-a;
    y4=y3-b;
  }
  
  if(x1<=x2&&y1>=y2){
    x3=x2+b;
    y3=y2+a;
    x4=x3-a;
    y4=y3+b;
  }
  
  if(x1>=x2&&y1<=y2){
    x3=x2-b;
    y3=y2-a;
    x4=x3+a;
    y4=y3-b;
  }
  
  if(x1>=x2&&y1>=y2){
    x3=x2+b;
    y3=y2-a;
    x4=x3+a;
    y4=y3+b;
  }
  
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl ;
}
    