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
  int k;
  cin >> k;
  if(k % 2 == 0) cout << k*k/4 << endl;
  else cout << k/2 * (k/2+1) << endl;
}
