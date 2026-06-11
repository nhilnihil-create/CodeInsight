#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  cin >> a;
  cin >> b;
  int x = (a+b) /2;
  if( (a+b)%2 == 0) {
    cout << x << endl;
  } else {
    cout << x+1 << endl;
  }
}
