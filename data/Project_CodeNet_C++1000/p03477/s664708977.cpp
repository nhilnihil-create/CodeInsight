#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  int d;

  cin >> a >> b >> c >> d;

  string s;

  if (a + b > c + d)
    s = "Left";
  else if (a + b == c + d)
    s = "Balanced";
  else
    s = "Right";

  cout << s << endl;
}
