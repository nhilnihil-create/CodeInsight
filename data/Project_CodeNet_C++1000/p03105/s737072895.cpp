#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  if(a*c <= b)
    cout << c << endl;
  else cout << b/a << endl;
}