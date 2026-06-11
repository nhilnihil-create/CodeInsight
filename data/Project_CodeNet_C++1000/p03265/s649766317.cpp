# include <iostream>
using namespace std;

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  int x_diff = x2 - x1;
  int y_diff = y2 - y1;
  
  x3 = x2 - y_diff;
  y3 = y2 + x_diff;
  x4 = x3 - x_diff;
  y4 = y3 - y_diff;
  
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  
  return 0;
}