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
  
  if(a >= b+1) 
    cout << a+a-1 << endl;
  else if(a == b)
    cout << a+b << endl;
  else if(b >= a+1)
    cout << b+b-1 << endl;
}