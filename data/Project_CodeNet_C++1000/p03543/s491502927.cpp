#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n,a,b,c,d;
  cin >> n;

  a = n/1000; 
  n %= 1000;
  b = n/100;
  n %= 100;
  c = n/10;
  d = n%10;

  if(a == b && b == c) cout << "Yes" << endl;
  else if(b == c && c == d) cout << "Yes" << endl;
  else cout << "No" << endl;

}