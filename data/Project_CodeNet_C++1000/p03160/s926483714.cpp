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
	ll n,i;
    scl(n);
    for(i=1;i<=n;i++)
    scl(ar[i]);
    
    dp[n]=0;
    for(i=n-1;i>=1;i--)
    {
    	if(i==n-1)
    	dp[i]=dp[i+1]+abs(ar[i]-ar[i+1]);
    	else
    	dp[i]=min(dp[i+1]+abs(ar[i]-ar[i+1]),dp[i+2]+abs(ar[i]-ar[i+2]));
	}
    printf("%lld\n",dp[1]);
}

