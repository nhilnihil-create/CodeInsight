#include <bits/stdc++.h>
using namespace std;
int mod  = 1e9+7;
int main() {
	// your code goes here
	
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	vector<vector<int>>comp(n,vector<int>(n));
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>comp[i][j];
	
	vector<long long>dp((1<<n));
	dp[0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		int m = __builtin_popcount(i);
		for(int w=0;w<n;w++)
		{
			if((i&(1<<w))==0 && comp[m][w]==1)
			{
				int j = (i|(1<<w));
				dp[j] = (dp[j]+dp[i]%mod)%mod;
			}
		}
	}
	
	long long res = dp[(1<<n)-1]%mod;
	cout<<res<<endl;
	return 0;
}