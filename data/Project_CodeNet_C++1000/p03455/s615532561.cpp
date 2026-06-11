#include <bits/stdc++.h>
using namespace std;

int main() {
  int c;
  double a, b, i;
  cin >> a >> b ;

  c = a * b / 2 ;
  i = a * b / 2 ;
  
  if (c - i == 0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}
