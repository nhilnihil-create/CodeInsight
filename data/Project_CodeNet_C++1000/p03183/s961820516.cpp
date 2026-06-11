#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
const int MAX_W = 10005;
typedef long long ll;

int n,w[MAX_N],s[MAX_N],v[MAX_N],sm[MAX_N];
ll dp[MAX_N][MAX_W];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d %d %d",w+i,s+i,v+i);
		sm[i]=i;
	}
	sort(sm+1,sm+1+n,[](const int &a, const int &b) {
		int d1=min(s[a]-w[b],s[b]);
		int d2=min(s[b]-w[a],s[a]);
		if (d1==d2)
			return a<b;
		return d1<d2;
	});
	for (int i=1; i<=n; i++)
		for (int j=0; j<MAX_W; j++)
		{
			dp[i][j]=dp[i-1][j];
			if (w[sm[i]]<=j)
				dp[i][j]=max(dp[i][j],
					v[sm[i]]+dp[i-1][min(s[sm[i]],j-w[sm[i]])]);
		}
	ll ans=0;
	for (int i=1; i<=n; i++)
		ans=max(ans,v[sm[i]]+dp[i-1][s[sm[i]]]);
	printf("%lld\n",ans);
	return 0;
}
