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
  int a[4];
  cin >> a[0] >> a[1] >> a[2];
  sort(a,a+3);

  cout << abs(a[2]-a[1]) + abs(a[1]-a[0]) << endl;
}