#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int main(){
	int m,k;
	m=read();
	k=read();
	if(k>=(1<<m))
	{
		puts("-1");
		return 0;
	}
	if(m==0)
	{
		puts("0 0");
		return 0;
	}
	if(m==1)
	{
		if(k==1)puts("-1");
		else puts("0 0 1 1");
		return 0;
	}
	for(int i=0;i<(1<<m);i++)
	{
		if(i==k)continue;
		printf("%d ",i);
	}
	printf("%d ",k);
	for(int i=(1<<m)-1;i>=0;i--)
	{
		if(i==k)continue;
		printf("%d ",i);
	}
	printf("%d ",k);
	return 0;
}