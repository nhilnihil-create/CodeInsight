#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'
#define F first
#define S second
const int MAX_N=3e3+3;
const int MOD=1000000007;

int n;
char s[MAX_N];
ll dp[MAX_N][MAX_N];
ll ans;

int main()
{
	scanf("%d",&n);
	scanf("%s",s+2);
	s[1]='<';
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='<') for(int j=1;j<=i;j++) dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
		else for(int j=i;j>=1;j--) dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
	}
	for(int i=1;i<=n;i++) ans=(ans+dp[n][i])%MOD;
	printf("%lld\n",ans);
	return 0;
}

