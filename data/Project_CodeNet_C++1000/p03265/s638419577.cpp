#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;

  int yd=abs(y2-y1);
  int xd=abs(x2-x1);
  if (x1 <= x2 && y1 < y2){
    x3 = x2 - yd;
    y3 = y2 + xd;
    x4 = x1 - yd;
    y4 = y1 + xd;
  }else if (x1 > x2 && y1 < y2){
    x3 = x2 - yd;
    y3 = y2 - xd;
    x4 = x1 - yd;
    y4 = y1 - xd;
  }else if (x1 > x2 && y1 >= y2){
    x3 = x2 + yd;
    y3 = y2 - xd;
    x4 = x1 + yd;
    y4 = y1 - xd;
  }else{
    x3 = x2 + yd;
    y3 = y2 + xd;
    x4 = x1 + yd;
    y4 = y1 + xd;
  }
  
  printf("%d %d %d %d\n",x3,y3,x4,y4);
}
