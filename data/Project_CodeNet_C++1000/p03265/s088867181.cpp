#include <bits/stdc++.h>
using namespace std;

void turn(int &vx, int &vy){
  int x, y;
  x = vx;
  y = vy;
  vx = -y;
  vy = x;
}

int main(){
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  int vx, vy;
  vx = x2 - x1;
  vy = y2 - y1;
  turn(vx, vy);
  x3 = x2 + vx;
  y3 = y2 + vy;
  turn(vx, vy);
  x4 = x3 + vx;
  y4 = y3 + vy;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << " " << endl;
  return 0;
}