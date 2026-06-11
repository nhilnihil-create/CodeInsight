#include<bits/stdc++.h>
using namespace std;
#define MN 1000
long long x[MN+5],y[MN+5];
int main()
{
	int n,i,j,u=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld%lld",&x[i],&y[i]);x[i]+=1e9;y[i]+=1e9;
		if((x[i]+y[i]+x[1]+y[1])&1)return 0*puts("-1");
	}
	if(~(x[1]+y[1])&1)u=1;
	printf("34\n%d %d ",(int)1e9+u,(int)1e9);
	for(i=0;i<=31;++i)printf("%u ",1<<i);puts("");
	for(i=1;i<=n;++i)
	{
		printf("LD");x[i]+=u;
		for(j=0;j<=30;++j)
			if((x[i]+y[i])&2)putchar(x[i]&1?'R':'U'),x[i]>>=1,y[i]>>=1;
			else putchar(x[i]&1?'L':'D'),x[i]=x[i]+1>>1,y[i]=y[i]+1>>1;
		puts(x[i]?"R":"U");
	}
}