#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c;
  d = b / a;
  if(c > d){
    cout << d;
  }
  else{
    cout << c;
  }
  return 0;
}