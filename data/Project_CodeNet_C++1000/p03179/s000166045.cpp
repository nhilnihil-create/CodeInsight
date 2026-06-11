#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int MOD = 1e9 + 7;

int32_t main() {
   IOS
   int n;cin>>n;
   string s;cin>>s;
   vector<vector<int>>dp(n+1,vector<int>(n+1));
   dp[1][1]=1;
   for(int i=1;i<=n;i++)
   dp[1][i]=1;
   for(int l=2;l<=n;l++)
   {
	   for(int i=1;i<l;i++)
	   {
		   if(s[l-2]=='<' ){
			   dp[l][i]+=dp[l-1][i-1];
			   dp[l][i]%=MOD;
		   }
		   else{
			   dp[l][i]+=dp[l-1][n]-dp[l-1][i-1]+MOD;
			   dp[l][i]%=MOD;
		   }
	   }
	   if( s[l-2]=='<' )
	   {
		   dp[l][l]+=dp[l-1][l];
		   dp[l][l]%=MOD;
	   }
	   for(int i=1;i<=n;i++)
	   {
		   dp[l][i]+=dp[l][i-1];
		   dp[l][i]%=MOD;
	   }
   }
   cout<< dp[n][n] << endl;
	   
    
		
	
	
  
}
 
 
