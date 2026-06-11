#include<bits/stdc++.h>

using namespace std;

string slowo;
long long int dp[3003][3003];
long long int n,i,j;

int main()
{
	cin >> n >> slowo;
	dp[0][0]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(slowo[i-1]=='<'){
                dp[i][j]=(dp[i-1][0]-dp[i-1][j]+1000000007)%1000000007;
			}
			else{
                dp[i][j]=dp[i-1][j];
			}
		}
		for(j=i;j>=0;j--){
            dp[i][j]=(dp[i][j]+dp[i][j+1])%1000000007;
		}
	}
	cout << dp[n-1][0];
}
