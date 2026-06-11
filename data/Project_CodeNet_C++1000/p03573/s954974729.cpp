#include <bits/stdc++.h>
using namespace std;

int main() {
int a, b, c;
  cin >> a >> b >> c;
  if(a == c && a!= b) cout << b << endl;
  else if (a == b && a!=c) cout << c << endl;
  else if(b == c && a!= c) cout << a << endl;
}
