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
  int mi = INF;
  for(int i = 0; i < s.size()-2; i++) {
    int num = (s[i]-'0')*100 + (s[i+1]-'0')*10
    + (s[i+2]-'0');
    mi = min(mi,abs(num-753));
  }
  cout << mi << endl;
}