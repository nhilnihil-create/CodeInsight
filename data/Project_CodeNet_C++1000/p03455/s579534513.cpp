#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string reply;

  cin >> a >> b;

  if (((a %= 2) == 0) || ((b %= 2) == 0)) {
    reply = "Even";
  } else {
    reply = "Odd";
  }
  cout << reply << endl;
}
