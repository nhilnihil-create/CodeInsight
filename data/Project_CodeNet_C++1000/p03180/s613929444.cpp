#include<bits/stdc++.h>
using namespace std;
int n,a[16][16],cnt;
bool vis[65536];
long long dp[65536];
vector<int>tmp;
long long dfs(int msk){
	if(msk==0)return 0;
	if(vis[msk])return dp[msk];
	for(int i=1;i<=msk-i;i++)
		if((msk|i)==msk)
			dp[msk]=max(dfs(i)+dfs(msk-i),dp[msk]);
	vis[msk]=1;
	return dp[msk];
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				for(int k=j+1;k<n;k++)
					if(i&(1<<k))
						dp[i]+=a[j][k];
	cout<<dfs((1<<n)-1);
}