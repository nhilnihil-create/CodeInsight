#include<iostream>
#include<string>
using namespace std;
string s,t;
int dp[3001][3001];
char ans[3005];
int main()
{
	cin>>s>>t;s=" "+s;t=" "+t;
	int ns=s.size()-1,nt=t.size()-1;
	for(int i=1;i<=ns;i++)
		for(int j=1;j<=nt;j++)
		{
			if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1;
			dp[i][j]=max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
		}
	int i=ns,j=nt,cnt=dp[i][j];ans[cnt+1]='0';
	while(i&&j)
		if(s[i]==t[j])
			ans[cnt--]=s[i],i--,j--;
		else if(dp[i][j]==dp[i-1][j])
			i--;
		else j--;
	for(int i=1;i<=dp[ns][nt];i++)
		cout<<ans[i];
	return 0;
}