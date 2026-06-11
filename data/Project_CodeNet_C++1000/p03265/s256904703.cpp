#include <iostream>
#include <algorithm>

int main(){
   int x1, y1, x2, y2;
   std::cin >> x1 >> y1 >> x2 >> y2;

   int x3, y3, x4, y4;
   int dx, dy;
   if ((x2 >= x1) && (y2 >= y1)){
      x3 = x2 - (y2 - y1);
      y3 = y2 + (x2 - x1);
      x4 = x3 - (x2 - x1);
      y4 = y3 - (y2 - y1);
   } else if ((x1 > x2) && (y2 >= y1)){
      x3 = x2 - (y2 - y1);
      y3 = y2 - (x1 - x2);
      x4 = x3 + (x1 - x2);
      y4 = y3 - (y2 - y1);
   } else if ((x1 > x2) && (y1 > y2)){
      x3 = x2 + (y1 - y2);
      y3 = y2 - (x1 - x2);
      x4 = x3 + (x1 - x2);
      y4 = y3 + (y1 - y2);
   } else if ((x2 >= x1) && (y1 > y2)){
      x3 = x2 + (y1 - y2);
      y3 = y2 + (x2 - x1);
      x4 = x3 - (x2 - x1);
      y4 = y3 + (y1 - y2);
   }
   std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
}

