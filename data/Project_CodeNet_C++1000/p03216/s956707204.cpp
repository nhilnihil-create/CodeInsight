// https://dwacon5th-prelims.contest.atcoder.jp/tasks/dwacon5th_prelims_c

#include<cstdio>
const int N=1e6+10;
int n,m,T,D[N],M[N],C[N],x,y;
char s[N];
long long sum,ans;
int main()
{
	scanf("%d%s%d",&n,s,&T);
	for(int i=0;i<n;i++)
		if(s[i]=='C')C[i+1]=1;
		else if(s[i]=='D')D[i+1]=1;
		else if(s[i]=='M')M[i+1]=1;
	while(T--)
	{
		scanf("%d",&m);
		ans=sum=x=y=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=m&&D[i-m])
			{
				x--;
				sum-=y;
			}
			if(i>=m&&M[i-m])y--;
			if(D[i])x++;
			if(M[i])
			{
				y++;
				sum+=x;
			}
			if(C[i])ans+=sum;
		}
		printf("%lld\n",ans);
	}
	return 0;
}