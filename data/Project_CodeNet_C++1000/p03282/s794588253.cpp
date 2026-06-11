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

const long x = 5000000000000000;
//5*10^15

int main() {
  string s;
  long k;
  cin >> s >> k;

  if(s[0] != '1') cout << s[0] << endl;
  else {
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] != '1') {
        num = i; break;
      }
    }
    if(num >= k) cout << 1 << endl;
    else cout << s[num] << endl;
  }
}