#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for(int i = 1;i <= 10;++i) {
    c = (a * c) - b;
    cout << c << endl;
  }
}
