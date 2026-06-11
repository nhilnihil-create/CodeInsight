#include <iostream>
using namespace std;

inline int dist(int x, int y) {
  if (x >= y) return x - y;
  else return y - x;
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if ((dist(a, c) <= d) || ((dist(a, b) <= d) && (dist(b, c) <= d))) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}