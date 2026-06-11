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
const long INF = 2000000000;

int main() {
  string s;
  cin >> s;

  int cnt1 = 0;;
  for(int i = 0; i < s.size(); i++) {
    if(i % 2 == 0 & s[i] == '0') cnt1++;
    if(i % 2 == 1 & s[i] == '1') cnt1++;
  }

  int cnt2 = 0;
  for(int i = 0; i < s.size(); i++) {
    if(i % 2 == 0 & s[i] == '1') cnt2++;
    if(i % 2 == 1 & s[i] == '0') cnt2++;
  }
  
  cout << min(cnt1,cnt2) << endl;
}