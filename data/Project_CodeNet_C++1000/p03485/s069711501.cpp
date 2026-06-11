#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  double a,b,ave;
  cin >> a >> b;

  ave = (a+b)/2;
  if(ave / (int)ave == 1)
    cout << ave << endl;
  else 
    cout << (int)ave + 1 << endl;
}