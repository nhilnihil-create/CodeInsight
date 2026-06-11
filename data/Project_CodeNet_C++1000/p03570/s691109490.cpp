#include<bits/stdc++.h>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
using namespace std;
template<typename T>inline void read(T &x)
{
	T s=0,f=1;char k=getchar();
	while(!isdigit(k)&&(k^'-'))k=getchar();
	if(!isdigit(k)){f=-1;k=getchar();}
	while(isdigit(k)){s=s*10+(k^48);k=getchar();}
	x=s*f;
}
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
}
const int MAXN=200010;
int n,ans;
int sum[MAXN];
int dp[1<<26];
char a[MAXN];
int main()
{
	scanf("%s",a+1);
	n=strlen(a+1);
	int i,j;
	sum[1]^=1<<(a[1]-'a');
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	For(i,1,n)
	{
		sum[i]=sum[i-1]^(1<<(a[i]-'a'));
		For(j,0,25)if(dp[sum[i]^(1<<j)]+1<dp[sum[i]])
			dp[sum[i]]=dp[sum[i]^(1<<j)]+1;
	}
	printf("%d\n",max(dp[sum[n]],1));
	return 0;
}

