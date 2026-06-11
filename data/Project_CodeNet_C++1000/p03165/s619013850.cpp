#include<bits/stdc++.h>
using namespace std;
#define int             long long
int dp[3001][3001];
 
    int ff(string &a, string &b,int n,int m,  int i, int j) {
 
 
  if (dp[i][j] != -1) {
 
    return dp[i][j];
  }
  if (i >= n || j >= m) {
 
    return 0;
  }
  if (a[i] == b[j]) {
    return dp[i][j] = 1 + ff(a, b,n,m,  i + 1, j + 1);
 
  }
  else {
    return dp[i][j] = max(ff(a, b,n,m, i + 1, j), ff(a, b,n,m, i, j + 1));
 
  }
}
    string f(string &a,string &b) {
 int n=a.length();
      int m= b.length();
        memset(dp, -1, sizeof dp);
  int len = ff(a, b,n,m, 0, 0);
  
  int i = 0;
  int j = 0;
  string c;
  while (len) {
    if (a[i] == b[j]) {
      c.push_back( a[i]);
      i++;
      j++;
      len--;
    } else {
      if (dp[i + 1][j] > dp[i][j + 1])
        i++;
      else j++;
    }
 
  }
  return c;
    }
int32_t main() {
 
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  string a,b;
  getline(cin, a);
 getline(cin, b);
 
 
  cout << f(a,b);
 
  return 0;
}
