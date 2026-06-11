#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[3001][3001];

string LCS(string s,string t,int len)
{
	string ls;
	int i=0,j=0;
	while(len>0)
	{
		if(s[i]==t[j])
		{
			ls.push_back(s[i]);
			i++;
			j++;
			len--;
		}
		else
		{
			if(dp[i][j+1]>dp[i+1][j])
				j++;
			else
				i++;
		}
	}
	return ls;
}

int lcs(string& s,string& t,int i,int j)
{
	if(i>=s.length() || j>=t.length())
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(s[i]==t[j])
		return dp[i][j]=1+lcs(s,t,i+1,j+1);
	else
		return dp[i][j]=max(lcs(s,t,i+1,j),lcs(s,t,i,j+1));
}
string solve(string s,string t)
{
	memset(dp,-1,sizeof(dp));
	int len=lcs(s,t,0,0);
	return  LCS(s,t,len);
}
int main()
{
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("ouput.txt","w",stdout);
// 	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t;
	cin >> s;
	cin >> t;
	cout << solve(s,t);
	return 0;
}