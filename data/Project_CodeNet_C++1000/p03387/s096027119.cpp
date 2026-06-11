#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if((max({a,b,c})*3-a-b-c)%2==0) {
    cout << (((max({a,b,c}))*3-a-b-c)/2) << endl;
  }
  else {
    cout << (((max({a,b,c}))*3-a-b-c)/2+2) << endl;
  }
}