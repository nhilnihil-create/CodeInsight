#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=1000010;
const int inf=2147483647;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,sum[Maxn];
char s[Maxn];
int main()
{
	n=read();
	scanf("%s",s+1);
	sum[0]=0;for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='M');
	int q=read();
	while(q--)
	{
		int k=read();
		LL ans=0,Sum=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i-k>0&&s[i-k]=='D')cnt--,Sum-=sum[i-k-1];
			if(s[i]=='C')ans+=cnt*sum[i]-Sum;
			if(s[i]=='D')cnt++,Sum+=sum[i-1];
		}
		printf("%lld\n",ans);
	}
}
