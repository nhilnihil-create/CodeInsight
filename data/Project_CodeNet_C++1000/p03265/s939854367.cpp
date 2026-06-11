#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int delta_x = x2 - x1;
  int delta_y = y2 - y1;
  int x3 = x2 - delta_y;
  int y3 = y2 + delta_x;
  delta_x = x3 - x2;
  delta_y = y3 - y2;
  int x4 = x3 - delta_y;
  int y4 = y3 + delta_x;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
