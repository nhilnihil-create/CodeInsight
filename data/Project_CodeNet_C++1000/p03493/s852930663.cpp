#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b = a/100;
  int c = a/10%10;
  int d = a%2;
  cout << b+c+d << endl;
}