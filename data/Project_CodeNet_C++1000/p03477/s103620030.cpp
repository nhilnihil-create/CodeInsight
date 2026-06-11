#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  string op;
  cin >> a >> b >> c >> d;

  if ((a+b) == (c+d) ) {
    cout << "Balanced" << endl;
  }
  else if ((a+b) > (c+d) ) {
    cout << "Left" << endl;
  }
  else if ((a+b) < (c+d) ) {
    cout << "Right" << endl;
  }
  else {
 cout << "Error" << endl;
}
}
  