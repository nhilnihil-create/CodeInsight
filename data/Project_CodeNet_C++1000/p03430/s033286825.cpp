#include<bits/stdc++.h>
using namespace std;
int x,dp[305][305][305];
int main()
{
	string s;cin>>s>>x;
	for(int i=0;i<s.size();i++)for(int j=0;j<s.size()-i;j++)
	{
		int fr=j,to=j+i;
		for(int k=0;k<=x;k++)
		{
			if(fr==to)dp[fr][to][k]=1;
			else dp[fr][to][k]=max(dp[fr][to][k],max(dp[fr][to-1][k],dp[fr+1][to][k])),dp[fr][to][k+(s[fr]!=s[to])]=max(dp[fr][to][k+(s[fr]!=s[to])],dp[fr+1][to-1][k]+2);
		}
	}
	printf("%d\n",dp[0][s.size()-1][x]);
	return 0;
}