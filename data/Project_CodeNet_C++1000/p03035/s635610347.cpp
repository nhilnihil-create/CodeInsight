#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  
  if(a >= 13)
    cout << b << endl;
  else if(a>=6 & a<=12)
    cout << b/2 << endl;
  else cout << "0" << endl;
}