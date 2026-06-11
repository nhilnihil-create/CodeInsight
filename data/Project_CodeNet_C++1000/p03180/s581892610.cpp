#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	vector<long long>dp;
	vector<vector<long long> >a;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	a.resize(n,vector<long long>(n));
	dp.resize(1<<n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=1;i<1<<n;i++)
		for(int j=0;j<n-1;j++)
			if(1<<j&i)
				for(int k=j+1;k<n;k++)
					if(1<<k&i)
						dp[i]+=a[j][k];
	for(int i=1;i<1<<n;i++)
		for(int j=(i-1)&i;j;j=(j-1)&i)
			dp[i]=max(dp[i],dp[j]+dp[i^j]);
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}