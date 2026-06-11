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

const long INF = 1e9 + 1;

int main() {
  int x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;
 
  int a = x2 - x1; 
  int b = y2 - y1; 

  cout << x2-b << " " << y2+a
  << " " << x1 - b << " " << y1+a << endl;    
}