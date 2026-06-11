#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(!n&&!m)printf("0 0"),exit(0);
	n=pow(2,n)-1;
	if(m>n||(n==1&&m==1))printf("-1"),exit(0);
	if(n==1&&m==0)printf("0 0 1 1"),exit(0);
	for(int i=0;i<=n;i++)if(i!=m)printf("%d ",i);
	printf("%d ",m);
	for(int i=n;i>=0;i--)if(i!=m)printf("%d ",i);
	printf("%d",m);
	return 0;
}