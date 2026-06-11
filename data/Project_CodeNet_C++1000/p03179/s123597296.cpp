#include<bits/stdc++.h>
using namespace std;
const int N=3011;
const int MOD=1e9+7;

int n;
char s[N];
int dp[N][N],sum[N];
void Add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

int main()
{
	
	scanf("%d%s",&n,&s);
	for(int i=1;i<=n;i++)
		dp[i-1][n-i]=1;
	for(int len=n-1;len>0;len--)
	{
		bool ok=(s[n-len-1]=='<');
		if(ok) for(int i=0;i<=len;i++) Add(dp[i][len-i-1],dp[i][len-i]);
		if(!ok) for(int i=1;i<=len;i++) Add(dp[i-1][len-i],dp[i][len-i]);
		if(ok) for(int i=1;i<=len;i++) Add(dp[i][len-i-1],dp[i-1][len-i]);
		if(!ok) for(int i=len-1;i>=0;i--) Add(dp[i][len-i-1],dp[i+1][len-i-2]);
	}
	printf("%d\n",dp[0][0]);
	
	return 0;
}