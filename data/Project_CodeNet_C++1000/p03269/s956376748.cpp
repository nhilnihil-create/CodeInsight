#include<cstdio>
int main()
{
	int l,n,m=0,i;
	scanf("%d",&l);
	for(n=0;1<<n<=l;++n);
	for(i=1;i<n;++i)if(l&(1<<i-1))++m;
	printf("%d %d\n",n,m+2*(n-1));
	for(i=1;i<n;++i)printf("%d %d %d\n%d %d %d\n",i,i+1,0,i,i+1,1<<i-1);
	for(m=1<<n-1,i=n;--i;)if(l&(1<<i-1))printf("%d %d %d\n",i,n,m),m+=1<<i-1;
}