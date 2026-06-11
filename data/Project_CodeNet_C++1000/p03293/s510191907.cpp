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
  string s,t;
  cin >> s >> t;
  
  bool flag = 0;
  for(int i = 0; i < s.size(); i++) {
    string a = s.substr(0,i);
    string b = s.substr(i);
    if(a+b == t | b+a == t) flag = 1;
  }

  if(flag)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}