#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a,b;
int main()
{
	n=read();a=read();b=read();
	if(1LL*a*b<n||a+b-1>n) return 0*puts("-1");
	for(int i=n-a+1;i<=n;++i) printf("%d ",i);
	int left=n-a-(b-1);
	for(int i=2,la=n-a;i<=b;++i)
	{
		int len=1+min(left,a-1);
		left-=len-1;la-=len;
		for(int j=1;j<=len;++j) printf("%d ",la+j);	
	}
	return 0;
}

