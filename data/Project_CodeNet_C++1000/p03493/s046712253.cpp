#include <bits/stdc++.h>
using namespace std;
int value(char x) {
  char c = '0';
  return (int)x - (int)c;
}
int main() {
  char a, b, c;
  cin >> a >> b >> c;
  cout << value(a) + value(b) + value(c) << endl;
}