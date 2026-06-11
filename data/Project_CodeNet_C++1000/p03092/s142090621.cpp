/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-23 14:48:50
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=10010;
const i64 inf=1ll<<50;
i64 n,a,b,p[N],f[N],F[N],ans;
int main()
{
	n=read(); a=read(); b=read(); ans=inf;
	fr(i,1,n) p[read()]=i;
	fr(i,1,n*2+1) f[i]=i<p[1]*2?b:i==p[1]*2?0:a;
	fr(i,2,n)
	{
		fr(j,1,n*2+1){ F[j]=f[j]; f[j]=inf; }
		i64 mf=inf;
		fr(j,1,n*2+1)
		{
			if(j&1) mf=std::min(mf,F[j]);
			f[j]=mf+(j<p[i]*2?b:j==p[i]*2?0:a);
			if(!(j&1)) mf=std::min(mf,F[j]);
		}
	}
	fr(i,1,n*2+1) ans=std::min(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}