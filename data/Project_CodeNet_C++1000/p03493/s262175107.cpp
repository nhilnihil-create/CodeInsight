#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,h,t,o;
  cin >> a;
  h=a/100;
  t=(a-h*100)/10;
  o=(a-h*100-t*10);
  cout << h+t+o << endl;
}