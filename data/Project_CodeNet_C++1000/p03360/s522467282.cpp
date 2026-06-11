#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;
 
  for(int i = 0; i < k; i++) {
    if(max({a,b,c}) == a) a *= 2;
    if(max({a,b,c}) == b) b *= 2;
    if(max({a,b,c}) == c) c *= 2;
  }
  cout << a + b + c << endl; 
}