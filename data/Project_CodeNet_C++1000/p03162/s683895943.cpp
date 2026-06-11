/*Rabbi Zidni Ilma*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld %lld",&n,&m)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define mod 10000007
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)

ll a[100005],b[100005],c[100005];
ll dp[100005][4];

int main()
{
	ll n,i,ans;
    scl(n);
    for(i=1;i<=n;i++)
    {
    	cin >> a[i] >> b[i] >> c[i];
	}
	for(i=n;i>=1;i--)
	{
		dp[i][1]=max(dp[i+1][2]+a[i],dp[i+1][3]+a[i]);
		dp[i][2]=max(dp[i+1][1]+b[i],dp[i+1][3]+b[i]);
		dp[i][3]=max(dp[i+1][1]+c[i],dp[i+1][2]+c[i]);
	}
	ans=max(dp[1][1],max(dp[1][2],dp[1][3]));
	printf("%lld\n",ans);
}