#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;

char c[maxn];
map<int,int> dp;
int ans[maxn];
int n,a[maxn];

int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]^(1<<(c[i]-'a'));
	dp.clear();
	dp[0]=0;
	ans[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		ans[i]=n+10;
		if (dp.find(a[i])!=dp.end()) ans[i]=dp[a[i]]+1;
		for(int j=0;j<26;j++)
		{
			if (dp.find(a[i]^(1<<j))==dp.end()) continue;
			ans[i]=min(ans[i],dp[a[i]^(1<<j)]+1);
		}
		if (dp.find(a[i])==dp.end())
			dp[a[i]]=ans[i];
		else dp[a[i]]=min(dp[a[i]],ans[i]);
	}
	
	printf("%d\n",ans[n]);
	return 0;
}