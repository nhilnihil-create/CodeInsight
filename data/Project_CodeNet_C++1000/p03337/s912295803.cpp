#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  if(a+b > a-b) {
      if(a+b > a*b) cout << a+b << endl;
      else cout << a*b << endl;
  }
  else {
      if(a-b > a*b) cout << a-b << endl;
      else cout << a*b << endl;
  }
}