#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = (a + b) - (c + d);
  cout << (x == 0 ? "Balanced" : (x > 0 ? "Left" : "Right")) << endl;
}
