#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,n;
  cin >> a >> b;
  if (a > b) {
    n += a;
    a--;
    n += a;
  } else if (b > a) {
    n += b;
    b--;
    n += b;
  } else {
    n += a;
    n += b;
  }
  cout << n << endl;
}