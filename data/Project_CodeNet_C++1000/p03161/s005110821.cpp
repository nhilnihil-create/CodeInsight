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

ll dp[100005],ar[100005];

int main()
{
	ll n,k,i,j;
    scll(n,k);
    for(i=1;i<=n;i++)
    scl(ar[i]);
    
    dp[n]=0;
    for(i=n-1;i>=1;i--)
    {
    	dp[i]=INT_MAX;
    	for(j=1;j<=k;j++)
    	{
    		if(i+j<=n)
    		dp[i]=min(dp[i],dp[i+j]+abs(ar[i]-ar[i+j]));
    		else
    		break;
		}
	}
    printf("%lld\n",dp[1]);
}

