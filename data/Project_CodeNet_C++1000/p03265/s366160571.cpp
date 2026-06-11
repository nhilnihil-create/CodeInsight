#include<iostream>
using namespace std;

int main()
{
  int x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  
  int dx = x1 - x0;
  int dy = y1 - y0;
  
  int x2 = x1 - dy;
  int y2 = y1 + dx;
  
  int x3 = x2 - dx;
  int y3 = y2 - dy;
  
  cout << x2 << " " << y2 << " " << x3 << " " << y3;
  return 0;
}