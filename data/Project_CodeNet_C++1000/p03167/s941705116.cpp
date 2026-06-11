#include<bits/stdc++.h>
#define pb push_back
#define INF 10000009
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int grid1(string s[],vector<vector<int>> &dp,int h,int w)
{
	if(h<0 || w<0)
	{
		return 0;
	}
	if(dp[h][w]!=-1)
	{
		return dp[h][w];
	}
	if(s[h][w]=='#')
	{
		return dp[h][w]=0;
	}
	return dp[h][w]=(grid1(s,dp,h-1,w)+grid1(s,dp,h,w-1))%1000000007;
}

int main()
{
	fastio
	int h,w,i,j;
	cin>>h>>w;
	char x;
	string s[h];
	for(i=0;i<h;i++)
	{
		s[i]="";
		for(j=0;j<w;j++)
		{
			cin>>x;
			s[i]+=x;
		}
	}
	vector<vector<int>> dp(h,vector<int>(w,-1));
	dp[0][0]=1;
	cout<<grid1(s,dp,h-1,w-1);
	/*for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
}