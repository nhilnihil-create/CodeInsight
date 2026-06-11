#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  cin >> d;
  string msg;
  switch (d) {
    case 25:
      msg = "Christmas";
      break;
    case 24:
      msg = "Christmas Eve";
      break;
    case 23:
      msg = "Christmas Eve Eve";
      break;
    case 22:
      msg = "Christmas Eve Eve Eve";
      break;

    default:
      break;
  }
  cout << msg << endl;
  return 0;
}