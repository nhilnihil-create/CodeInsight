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
  int n;
  cin >> n;

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int cnt = 0;
    for(int j = 1; j <= i; j++) {
      if(i % j == 0) cnt++;
    }
    if(cnt == 8) ans++;
    i++;
  }
  cout << ans << endl;
}
