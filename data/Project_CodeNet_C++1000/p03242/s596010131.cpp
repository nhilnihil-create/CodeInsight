#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  if (X / 100 == 1) {
    cout << 9;
  }
  else {
    cout << 1;
  }
  if ((X % 100) / 10 == 1) {
    cout << 9;
  }
  else {
    cout << 1;
  }
  if (X % 10 == 1) {
    cout << 9;
  }
  else {
    cout << 1;
  }
  cout << endl;
}