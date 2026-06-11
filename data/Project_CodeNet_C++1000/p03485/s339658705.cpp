#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int wa = (a + b);
  //cout << a << endl;
  //割られる数をa、 割る数をbとした時、
  //(a + (b-1)) / b
  int h = (wa + (2 - 1)) / 2;
  cout << h << endl;
  
  return 0;
}
