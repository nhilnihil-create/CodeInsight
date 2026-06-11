#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

int n,m;
int pre[20];
int dp[maxn];
int cnt[]={0,2,5,5,4,5,6,3,7,6};

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	} 
	return x*f;
}

int main()
{
	n=read(), m=read();
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	while(m--)
	{
		int x=read();
		pre[x]=1;
		for(int i=cnt[x];i<=n;i++)
			dp[i]=max(dp[i],dp[i-cnt[x]]+1);
	}	
	
	int tmp=n;
	while(tmp)
	{
		for(int i=9;i;i--)
		{
			if(pre[i] && tmp>=cnt[i] && dp[tmp-cnt[i]]==dp[tmp]-1)
			{
				cout<<i;
				tmp-=cnt[i];
				break;
			}
		}
	}
	
//	system("pause");
	return 0;
} 