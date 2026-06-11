#include<bits/stdc++.h>
using namespace std;

int main(){
  int x1,x2,y1,y2;
  int x3,x4,y3,y4;
  
  cin >> x1 >> y1 >> x2 >> y2;
  
  if(x2-x1>=0&&y2-y1>=0){
    x3 = x2 + (-1)*abs(y2-y1);
    y3 = y2 + abs(x2-x1);
    x4 = x3 + (-1)*abs(x2-x1);
    y4 = y3 + (-1)*abs(y2-y1);
  }
  else if(x2-x1<=0&&y2-y1>=0){
    x3 = x2 + (-1)*abs(y2-y1);
    y3 = y2 + (-1)*abs(x2-x1);
    x4 = x3 + abs(x2-x1);
    y4 = y3 + (-1)*abs(y2-y1);
      
  }
  else if(x2-x1<=0&&y2-y1<=0){
    x3 = x2 + abs(y2-y1);
    y3 = y2 + (-1)*abs(x2-x1);
    x4 = x3 + abs(x2-x1);
    y4 = y3 + abs(y2-y1);
  }
  else if(x2-x1>=0&&y2-y1<=0){
    x3 = x2 + abs(y2-y1);
    y3 = y2 + abs(x2-x1);
    x4 = x3 + (-1)*abs(x2-x1);
    y4 = y3 + abs(y2-y1);
  }
  
  cout << x3 << " ";
  cout << y3 << " ";
  cout << x4 << " ";
  cout << y4 << " ";
}