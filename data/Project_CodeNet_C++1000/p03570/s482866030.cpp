/******************************************
*    AUTHOR:         CHIRAG AGARWAL       *
*    INSTITUITION:   BITS PILANI, PILANI  *
******************************************/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef long double LD;
const int MAX=2e5+5;
int pre[26][MAX];
int dp[MAX];
int mask[MAX];
map<int,int> mp;
string s;

int main() 
{
	memset(dp,-1,sizeof dp);
	cin>>s;

	pre[s[0]-'a'][0]=1;

	for(int i=1;i<s.length();i++)
	{
		for(int j=0;j<26;j++)
		{
			if((s[i]-'a')==j)
			{
				pre[j][i]=pre[j][i-1]+1;
			}
			else
			{
				pre[j][i]=pre[j][i-1];
			}
		}
	}

	for(int i=0;i<s.length();i++)
	{
		int msk=0;
		for(int j=0;j<26;j++)
		{
			if(pre[j][i]%2)
			{
				msk^=(1<<j);
			}
		}
		mask[i+1]=msk;
	}
	dp[s.length()+1]=0;
	for(int i=s.length();i>=1;i--)
	{
		int ans=s.length()-i+1;
		if(mp.find(mask[i-1])!=mp.end())
		{
			ans=min(ans,dp[mp[mask[i-1]]+1]+1);
		}
		for(int j=0;j<26;j++)
		{
			if(mp.find(mask[i-1]^(1<<j))!=mp.end())
			{
				ans=min(ans,1+dp[mp[(mask[i-1]^(1<<j))]+1]);
			}
		}
		ans=min(ans,dp[i+1]+1);
		if(mp.find(mask[i])!=mp.end())
		{
			if(ans<dp[mp[mask[i]]])
			mp[mask[i]]=i;
		}
		else
		{
			mp[mask[i]]=i;
		}
		dp[i]=ans;
///		printf("%d\n",dp[i]);
	}
	printf("%d\n",dp[1]);
	return 0;
}	
