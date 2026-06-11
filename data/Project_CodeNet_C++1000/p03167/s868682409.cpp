/*Rabbi Zidni Ilma*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define mod 1000000007
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)

char s[1000][1000];
ll dp[1005][1005];

int main()
{
	ll H,W,i,j;
	scll(H,W);
	for(i=0;i<H;i++)
	{
		for(j=0;j<W;j++)
		{
			cin >> s[i][j];
		}
	}
	dp[0][1]=1;
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(s[i-1][j-1]=='.')
			dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
			else
			dp[i][j]=0;
		}
	}
	ll ans=dp[H][W]%mod;
	printf("%lld\n",ans);
}