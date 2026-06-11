#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  int m = b;
  if (a < 13) {
    m /= 2;
    if (a < 6) {
      m = 0;
    }
  }
  cout << m << endl;
}