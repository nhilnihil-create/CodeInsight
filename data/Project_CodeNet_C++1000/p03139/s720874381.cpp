#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
} 

int main()
{
	int n,a,b,ans;
	n=read(),a=read(),b=read();
	ans=a+b-n;
	if (ans<0) ans=0;
	printf("%d %d\n",min(a,b),ans);
	return 0;
}