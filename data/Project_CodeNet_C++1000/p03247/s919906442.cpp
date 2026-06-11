/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-02 14:29:25
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
#include<iostream>
#include<string.h>
#define i64 long long
const int N=1010;
int n,x[N],y[N],d[N],m;
std::string ans[N];
i64 calc(i64 a,i64 b){ return std::abs(a)+std::abs(b); }
int main()
{
	n=read();
	fr(i,1,n){ x[i]=read(); y[i]=read(); }
	fr(i,2,n) if((x[i]+y[i]+x[1]+y[1])%2){ printf("-1\n"); return 0; }
	if((x[1]+y[1])%2)
	{
		d[++m]=1;
		fr(i,1,n){ ans[i]+='U'; y[i]--; }
	}
	d[++m]=1; d[++m]=1;
	fd(i,30,0) d[++m]=1<<i;
	d[++m]=1;
	fr(i,1,n)
	{
		ans[i]+='U'; y[i]--;
		if(y[i]&1){ ans[i]+='U'; y[i]--; }
		else{ ans[i]+='R'; x[i]--; }
		fd(j,30,0)
		{
			if(calc(x[i]+(1<<j),y[i])<=(1<<j)){ x[i]+=(1<<j); ans[i]+='L'; }
			else if(calc(x[i]-(1<<j),y[i])<=(1<<j)){ x[i]-=(1<<j); ans[i]+='R'; }
			else if(calc(x[i],y[i]+(1<<j))<=(1<<j)){ y[i]+=(1<<j); ans[i]+='D'; }
			else if(calc(x[i],y[i]-(1<<j))<=(1<<j)){ y[i]-=(1<<j); ans[i]+='U'; }
		}
		if(x[i]==1) ans[i]+='R';
		else if(x[i]==-1) ans[i]+='L';
		else if(y[i]==1) ans[i]+='U';
		else if(y[i]==-1) ans[i]+='D';
//		printf("%d %d\n",x[i],y[i]);
	}
	printf("%d\n",m);
	fr(i,1,m) printf("%d%c",d[i],i==m?'\n':' ');
	fr(i,1,n) std::cout<<ans[i]<<std::endl;
	return 0;
}