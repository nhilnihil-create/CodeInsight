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
  int n,k,h[110000];
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> h[i];

  vector<long> dp(n, INF);
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  for(int i = 2; i < n; i++) {
    for(int j = 1; j < k+1; j++) {
      if(i >= j)
        dp[i] = min(dp[i-j] + abs(h[i]-h[i-j]), dp[i]);
    }
  }
  cout << dp[n-1] << endl;
}