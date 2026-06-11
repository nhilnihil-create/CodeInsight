#include <bits/stdc++.h>
using namespace std;

int main() {
  string X, Y;
  int x, y;
  cin >> X >> Y;
  if(X == "A") {
    x = 10;
  }
  if(X == "B") {
    x = 11;
  }
  if(X == "C") {
    x = 12;
  }
  else if(X == "D") {
    x = 13;
  }
  else if(X == "E") {
    x = 14;
  }
  else if(X == "F") {
    x = 15;
  }
  if(Y == "A") {
    y = 10;
  }
  if(Y == "B") {
    y = 11;
  }
  if(Y == "C") {
    y = 12;
  }
  if(Y == "D") {
    y = 13;
  }
  if(Y == "E") {
    y = 14;
  }
  if(Y == "F") {
    y = 15;
  }
  if(x < y) {
    cout << "<" << endl;
  }
  if(x == y) {
    cout << "=" << endl;
  }
  if(x > y) {
    cout << ">" << endl;
  }
}
