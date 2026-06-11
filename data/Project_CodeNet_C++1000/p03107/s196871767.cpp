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

int main() {
  string s;
  cin >> s;

  int cnt1 = 0, cnt2 = 0;
  for(int i = 0; i < s.size(); i++) {
      if(s[i] == '0') cnt1++;
      else if (s[i] == '1') cnt2++;
  }
  cout << 2 * min(cnt1, cnt2) << endl;
}
