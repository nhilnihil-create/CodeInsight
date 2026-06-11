#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s;
  cin >> s;
  int x;
  x = s % 10;
  s = s / 10;
  x = x + s % 10;
  s = s / 10;
  x = x + s;
  cout << x << endl;
}