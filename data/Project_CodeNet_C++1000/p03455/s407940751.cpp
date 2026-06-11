#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  int c, d;
  c = a % 2;
  d = b % 2;
  
  if (c == 0 || d == 0){
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}