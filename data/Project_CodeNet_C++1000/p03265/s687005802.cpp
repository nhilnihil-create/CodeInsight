#include <iostream>
#include <cmath>
using namespace std;
typedef struct {
  int x;
  int y;
} PT;
int main()
{
  PT pt[4];
  cin >> pt[0].x >> pt[0].y >> pt[1].x >> pt[1].y;
  int x_diff = pt[1].x - pt[0].x;
  int y_diff = pt[1].y - pt[0].y;

  pt[2].x = pt[1].x - y_diff;
  pt[2].y = pt[1].y + x_diff;

  pt[3].x = pt[2].x - x_diff;
  pt[3].y = pt[2].y - y_diff;

  cout << pt[2].x << " " << pt[2].y << " " << pt[3].x << " " << pt[3].y << endl;
  return 0;
}
