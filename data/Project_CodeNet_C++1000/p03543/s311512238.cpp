#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  //数字を「dcba」と書いている＠以下の4行
  int a, b, c, d;
  a = N % 10;
  b = (N - a) / 10 % 10;
  c = (N - a - 10 * b) /100 % 10;
  d = (N - a - 10 * b - 100 * c) / 1000 % 10;
  
  cin >> a >> b >> c >> d;
  
  if ( a == b && b == c ) {
    cout << "Yes" << endl;
  }
  else if ( c == d && b == c) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
