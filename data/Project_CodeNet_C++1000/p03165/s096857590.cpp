#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
const ll mod = 1e9 + 7;
ll inf = 1e16;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main()
{
   fastio;
   string s1,s2;
   cin>>s1>>s2;
   int m,n;
   m = s1.length(), n = s2.length();
   int dp[m+1][n+1];
   for(int i=0;i<=m;++i){
   	for(int j=0;j<=n;++j){
   		 if(i==0||j==0){
   		 	dp[i][j] = 0;
			}else{
				if(s1[i-1]==s2[j-1]){
					dp[i][j] = 1 + dp[i-1][j-1];
				}else{
				  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);	
				}
			}
	   }
   }
   //cout<<dp[m][n]<<endl;
   string ans = "";
   int i = m;
   int j = n;
   while(i>0 && j>0){
   	   if(s1[i-1]==s2[j-1]){
   	   	    ans = s1[i-1] + ans;
   	   	    i-=1;
   	   	    j-=1;
		  }else{
		  	 if(dp[i-1][j]> dp[i][j-1]){
		  	 	i = i-1;
			   }else{
			   	j = j-1;
			   }
		  }
   }
   cout<<ans<<endl;
   
	return 0;
}

