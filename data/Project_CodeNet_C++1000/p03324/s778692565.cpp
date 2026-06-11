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
  int d,n;
  cin >> d >> n;
  
  int cnt = 0, num = 1, ans;
  while(cnt != n) {
    ans = num;
    int cnt2 = 0;
    while(num % 100 == 0) {
      num /= 100;
      cnt2++;
    }
    if(cnt2 == d) cnt++;
    
    num = ans + 1;
  }
  cout << ans << endl;
}