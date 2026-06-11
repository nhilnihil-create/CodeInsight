#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[100005];
ll a[25][25],val[100005],dp[100005];
vector<int>vec,used[25];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) 
		cin>>a[i][j];
	for(int i=0;i<(1<<n);i++)
	{
		vector<int>v;
		vec=v;
		for(int j=0;j<n;j++)
			if(i&(1<<j))vec.push_back(j+1);
		for(int x=0;x<(int)vec.size();x++)
			for(int y=x+1;y<(int)vec.size();y++)
				val[i]+=a[vec[x]][vec[y]];
	}
	for(int i=0;i<(1<<n);i++)
	{
		b[i]=b[i>>1]+(i&1);
		used[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)used[i].size();j++)
		{
			int k=used[i][j];
			dp[k]=val[k];
			for(int sub=k;sub;sub=(sub-1)&k)
				dp[k]=max(dp[k],dp[sub]+val[k^sub]);
		}
	}
	cout<<dp[(1<<n)-1];
	return 0;
}