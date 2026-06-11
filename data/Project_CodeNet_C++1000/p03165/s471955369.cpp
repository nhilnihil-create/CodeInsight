#include<bits/stdc++.h>
using namespace std;
string s, t;
int n, m;
long long dp[3005][3005];
int main(){
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(s[i]==t[j]) dp[i+1][j+1] = max({dp[i][j]+1, dp[i+1][j], dp[i][j+1]});
      else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    }
  }
  n--;
  m--;
  stack<char> st;
  st.push('\n');
  while(n>=0 && m>=0){
    if(s[n]==t[m]){
      st.push(s[n]);
      n--;
      m--;
    }
    else if(dp[n][m+1]==dp[n+1][m+1]) n--;
    else m--;
  }
  while(!st.empty()){cout << st.top(); st.pop();}
}