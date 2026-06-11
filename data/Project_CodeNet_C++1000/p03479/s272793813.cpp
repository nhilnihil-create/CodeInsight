#include<iostream>
using namespace std;

int main() {
  long X, Y; cin >> X >> Y;
  int l = 0;
  while (X <= Y) {
    l++;
    X *= 2;
  }
  cout << l << endl;
}