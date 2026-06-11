#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  bool bb = true;
  if (abs(a - c) <= d)
  {
    bb = true;
  }
  else
  {
    if (abs(a - b) > d) bb = false;
    if (abs(b - c) > d) bb = false;
  }
  if (bb) cout << "Yes" << endl;
  else    cout << "No" << endl;
}