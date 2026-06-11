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
  int a;
  cin >> a;
  if(a < 1200) 
    cout << "ABC" << endl;
  else if(a < 2800)
    cout << "ARC" << endl;
  else cout << "AGC" << endl;
}