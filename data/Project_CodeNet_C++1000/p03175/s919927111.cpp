#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MAX 100005
#define MOD 1000000007
vector <int> v[MAX];
int dp[MAX][2];
void dfsdp(int x,int y)
{
	dp[x][0]=1;
	dp[x][1]=1;
	for(auto i:v[x])
	{
		if(i!=y)
		{
			dfsdp(i,x);
			dp[x][0]=(dp[x][0]*((dp[i][1]+dp[i][0])%MOD))%MOD;
			dp[x][1]=(dp[x][1]*dp[i][0])%MOD;
		}
	}
}
signed main()
{
	int n,i;
	cin>>n;
	for(i=1;i<n;i++)
	{
		int k1,k2;
		cin>>k1>>k2;
		v[k1].push_back(k2);
		v[k2].push_back(k1);
	}
	dfsdp(1,1);
	cout<<(dp[1][0]+dp[1][1])%MOD<<"\n";
}