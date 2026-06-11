#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int x, y;
  x = a % 2;
  y = b % 2;
  
  if(x==0 || y==0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}