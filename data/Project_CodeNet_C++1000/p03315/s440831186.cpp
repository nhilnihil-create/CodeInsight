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
  string s;
  cin >> s;
  int sum = 0;
  for(int i = 0; i < 4; i++) {
    if(s[i] == '+') sum++;
    else sum--;
  }
  cout << sum << endl;
}