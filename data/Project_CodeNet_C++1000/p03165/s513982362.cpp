#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int llu;

int dp[3001][3001];
/*  Memoized LCS
int lcs(string a,string b,int n,int m){
	if(n==0 || m==0){
		return 0;
	}
	if(dp[n][m]!= (-1)){
		return dp[n][m];
	}
	if(a[n-1]==b[m-1]){
		return dp[n][m]=1+lcs(a,b,n-1,m-1);
	}
	else{
		return dp[n][m] =  max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
	}
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int n,m;
    n=a.length();
    m=b.length();
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=m;j++){
    		if(i==0 || j==0){
    			dp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
    //cout<<lcs(a,b,a.size(),b.size());
    //length of lcs
    //cout<<dp[n][m]<<"\n";
    //Printing lcs
    int i=n,j=m;
    string res="";
    while(i>0 && j>0){
    	if(a[i-1]==b[j-1]){
    		res.push_back(a[i-1]);
    		i--,j--;
		}
		else{
			if(dp[i][j-1] >= dp[i-1][j]){
				j--;
			}
			else{
				i--;
			}
		}
	}
	reverse(res.begin(),res.end());
	cout<<res;
    return 0;
}
