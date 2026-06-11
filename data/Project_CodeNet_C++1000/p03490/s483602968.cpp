#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
  string s;
  cin >> s;

  int x, y;
  cin >> x >> y;

  vector<int> dx, dy;
  int runlength = 0;
  bool isx = true;

  for (char c : s) {
    if (c == 'F') {
      ++runlength;
      continue;
    }
    if (isx) {
      dx.push_back(runlength);
    } else {
      dy.push_back(runlength);
    }
    runlength = 0;
    isx = !isx;
  }

  if (isx) {
    dx.push_back(runlength);
  } else {
    dy.push_back(runlength);
  }

  const int geta = 8000;

  bitset<16010> dpx, dpy;
  dpx.set(dx[0] + geta);
  dpy.set(0 + geta);

  dx.erase(dx.begin());
  for (int d : dx) {
    dpx = (dpx << d) | (dpx >> d);
  }

  for (int d : dy) {
    dpy = (dpy << d) | (dpy >> d);
  }

  bool res = dpx[x + geta] && dpy[y + geta];

  cout << (res ? "Yes" : "No") << endl;

  return 0;
}
