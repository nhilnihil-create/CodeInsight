#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,th,h,t,o;
  cin >> a;
  
  th = a / 1000;
  h = (a % 1000) / 100;
  t = (a % 100) / 10;
  o = a % 10;
  
  if (((th == h) && (h == t)) || ((h == t) && (t == o))) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}