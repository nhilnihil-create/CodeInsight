#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int vect_x=x2-x1;
  int vect_y=y2-y1;

  int x3,x4,y3,y4;

  x3=x2-vect_y;
  y3=y2+vect_x;
  x4=x1-vect_y;
  y4=y1+vect_x;
  
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

  return 0;
}
