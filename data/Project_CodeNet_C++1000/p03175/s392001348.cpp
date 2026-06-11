#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[100005][2];
const ll mod=1e9+7;
vector<int>vec[100005];
void dfs(int pre,int pst)
{
	dp[pre][0]=1;
	dp[pre][1]=1;
	for(int i=0;i<vec[pre].size();i++)
	{
		int to=vec[pre][i];
		if(to!=pst)
		{
			dfs(to,pre);
			dp[pre][0]*=dp[to][0]+dp[to][1];
			dp[pre][0]%=mod;
			dp[pre][1]*=dp[to][0];
			dp[pre][1]%=mod;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1,-1);
	cout<<(dp[1][0]+dp[1][1])%mod;
	return 0;
} 