#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ba = b - a > 0 ? b - a : -(b - a);
  int cb = c - b > 0 ? c - b : -(c - b);
  int ca = c - a > 0 ? c - a : -(c - a);
  if (ba <= d && cb <= d || ca <= d) {
  	cout << "Yes" << endl;
  } else {
  	cout << "No" << endl;
  }
}
