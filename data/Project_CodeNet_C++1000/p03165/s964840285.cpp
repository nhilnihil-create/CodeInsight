#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 3e3+5;

string s , t;
char a[N] , b[N];
int dp[N][N];
vector<char> vec;

int LCS(int n , int m){
  if(dp[n][m] != -2) return dp[n][m];
  if(!n || !m) return dp[n][m] = 0;
  if(a[n] == b[m]) return dp[n][m] = max(dp[n][m],1+LCS(n-1,m-1));
  return dp[n][m] = max(dp[n][m],max(LCS(n-1,m),LCS(n,m-1)));
}

void rec(int n , int m){
  if(!n || !m) return;
  if(a[n] == b[m]) vec.pb(a[n]) , rec(n-1,m-1);
  else if(dp[n][m] == dp[n-1][m]) rec(n-1,m);
  else if(dp[n][m] == dp[n][m-1]) rec(n,m-1);
}

int main(){

  ios_base::sync_with_stdio(),cin.tie(0);

  cin >> s >> t;
  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < N ; j++) dp[i][j] = -2;
  for(int i = 0 ; i < s.size() ; i++) a[i+1] = s[i];
  for(int i = 0 ; i < t.size() ; i++) b[i+1] = t[i];
  
  LCS(s.size(),t.size()) , rec(s.size(),t.size());

  for(int i = vec.size()-1 ; i >= 0 ; i--) cout << vec[i];
  cout << "\n";

}
