#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
char s[N];
int minn[1<<26],pos[N],pre[N],dp[N],n;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		int f=s[i]-'a';
		pre[i]=pre[i-1]^(1<<f);
		dp[i]=dp[i-1]+1;
			if(minn[pre[i]]==0&&pre[i]!=0)	minn[pre[i]]=inf;
		dp[i]=min(dp[i],minn[pre[i]]+1);
		for(int j=0;j<26;++j)
		{
			int k=pre[i]^(1<<j);
				if(minn[k]==0&&k!=0)	minn[k]=inf;
			dp[i]=min(dp[i],minn[k]+1);
		}
		minn[pre[i]]=min(dp[i],minn[pre[i]]);
	}
	printf("%d\n",dp[n]);
	return 0;
}