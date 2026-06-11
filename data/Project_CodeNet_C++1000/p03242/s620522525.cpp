#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int x = a/100;
  int y = a%100/10;
  int z = a%10;
  if (x == 1) {
    x = 9;
  }
  else {
  if (x == 9) {
    x = 1;
  }
  }
  if (y == 1) {
    y = 9;
  }
  else {
  if (y == 9) {
    y = 1;
  }
  }
  if (z == 1) {
    z = 9;
  }
  else {
  if (z == 9) {
    z = 1;
  }
  }
  cout << x*100+y*10+z << endl;
}