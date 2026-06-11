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
  string s;
  cin >> s;
  for(int i = 0; i < 3; i++) {
    if(s[i] == '1') s[i] = '9';
    else s[i] = '1';
  }
  cout << s << endl;
}
