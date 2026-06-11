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
int a,b,c;
int main()
{
	a=read(),b=read(),c=read();
	if(c<=b)
	printf("%d\n",b+c);
	else
	{
		int ans=0;
		if(a+b<c)
		{
			
			ans=2*b;
			c-=b;
			ans+=a+1;
		}
		else
		{
			ans=b+c;
		}
		printf("%d\n",ans);
	}
	return 0;
}