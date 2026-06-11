#include <bits/stdc++.h>
using namespace std ;
const int mxN =3e3+3 ;
string s,t ;
int dp[mxN][mxN] ;
signed main(){	  
  cin >> s >> t ;
  int n = s.size(),m=t.size() ;
  for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
    	if(s[i-1]==t[j-1])
          dp[i][j]=1+dp[i-1][j-1] ;
      	else 
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
    }
  }
  string ans ;
  int i=n,j=m ;
  while(i>0&&j>0){
  	if(dp[i][j]==dp[i-1][j])
      --i ;
   	else if(dp[i][j]==dp[i][j-1])
      --j ;
    else
      --i,--j,ans+=s[i] ;
  }
  reverse(ans.begin(),ans.end()) ;
  cout << ans << endl ;
}