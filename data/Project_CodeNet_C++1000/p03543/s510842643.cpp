#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b = a/1000;
  int c = a%1000/100;
  int d = a%1000%100/10;
  int e = a%1000%100%10;
  if (b == c && c == d ){
    cout << "Yes" << endl;
  }
  else if (c == d && d == e ){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
