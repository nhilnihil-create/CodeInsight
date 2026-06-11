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
  bool flag = 1;
  if(s[0] != 'A') flag = 0;

  int cnt = 0;
  for(int i = 2; i <= s.size()-2; i++)
    if(s[i] == 'C') cnt++;

  if(cnt != 1) flag = 0;

  int cnt2 = 0;
  for(int i = 0; i < s.size(); i++) 
    if(s[i] != tolower(s[i])) cnt2++;
  
  if(cnt2 != 2) flag = 0;

  if(flag)
    cout << "AC" << endl;
  else cout << "WA" << endl;
}