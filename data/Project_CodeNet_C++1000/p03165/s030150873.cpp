#include <bits/stdc++.h>
using namespace std;
int solve(string s1,string s2,int m,int n)
{
	if(m==0||n==0)
		return 0;
	if(s1[m-1]==s2[n-1])
		return 1+solve(s1,s2,m-1,n-1);
	else
		return max(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
}
string solution(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0 ; i<=m ; i++)
	{
		for(int j=0 ; j<=n ; j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	int i=m,j=n;
	string str="";
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			str+=s1[i-1];
			i--;
			j--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j])
				j--;
			else
				i--;
		}
	}
	return str;
//	return dp[m][n];
}
int main() {
	string x,y;
	cin>>x>>y;
	string ans=solution(x,y,x.size(),y.size());
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}