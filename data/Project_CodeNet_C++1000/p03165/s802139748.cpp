#include<bits/stdc++.h>
using namespace std;

int dp[3005][3005];

string lcs(string s, string t, int m, int n) {
  string r = "";
  for(int i=0; i<=m; i++) {
    for(int j=0; j<=n; j++) {
      if(i==0 || j==0) dp[i][j] = 0;
      else if(s[i-1] == t[j-1]) {
          dp[i][j] = 1 + dp[i-1][j-1];
      }
      else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
  }
  int i=m,j=n;
  while(i>0 && j>0) {
    if(s[i-1] == t[j-1]) {
        r += s[i-1];
        i=i-1;
        j=j-1;
    }
    else {
        if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
  }
  return r;
}

int main() {
  int n,m;
  string s,t;
  cin>>s>>t;
  m = s.size();
  n = t.size();
  string r = lcs(s,t,m,n);
  string rev = string(r.rbegin(),r.rend()); 
  cout<<rev;
}