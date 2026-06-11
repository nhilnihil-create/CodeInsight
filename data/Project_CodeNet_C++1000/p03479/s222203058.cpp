#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

int main() {
  long x, y;
  cin >> x >> y;

  long cnt = 1;
  while(2 * x <= y) {
    cnt++; 
    x *= 2;
  }
  
  cout << cnt << endl;
}
