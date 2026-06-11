#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b,t,sum = 0;
  cin >> a >> b >> t;
  
  int T;
  for(int i = 1; T < t+0.5; i++) {
    T = a*i;
    sum += b;
  }
  cout << sum-b << endl;
}