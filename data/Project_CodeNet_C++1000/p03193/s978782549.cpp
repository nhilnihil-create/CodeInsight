#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
#include<cmath>
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 1005
using namespace std;
int read()
{
    int l=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
        w=-1;
        else
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
    {
        l*=10;
        l+=ch-'0';
        ch=getchar();
    }
    return l*w;
}
int n,h,w;
int main()
{
	n=read(),h=read(),w=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		a=read(),b=read();
		while(a-h>=0&&b-w>=0)
		{
			ans++;
			a-=h;
			b-=w;
		}
	}
	printf("%d\n",ans);
	return 0;
}