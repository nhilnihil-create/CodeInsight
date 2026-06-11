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

const long INF = (1<<30);
 
int main() {
  long s;
  cin >> s;
  if(s == 1 || s == 2) {
    cout << 4 << endl;
    return 0;
  }
  for(long i = 1; ; i++) {
    if(s % 2 == 0) {
      if(s == 4) {
        cout << i+3 << endl;
        return 0;
      }
      else s /= 2;    
    } 
    else s = 3*s + 1;
  }
}