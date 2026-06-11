#include <bits/stdc++.h>
using namespace std;

int main() {

  int a, b, c, d;
  cin >> a >> b >> c >>d;
  
  if((c-a)*(c-a)<=d*d || ((b-a)*(b-a)<=d*d && (c-b)*(c-b)<=d*d)) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}