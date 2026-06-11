#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=300010;
const int inf=2147483647;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
LL n,a,b;
int main()
{
	n=read(),a=read(),b=read();
	if(a+b>n+1)return puts("-1"),0;
	if((b-1)*a<n-a)return puts("-1"),0;
	if(b==1)
	{
		if(a!=n)return puts("-1"),0;
		for(int i=1;i<=n;i++)printf("%d ",i);
		return 0;
	}
	int t=(n-a)/(b-1),r=(n-a)%(b-1),cur=n-a;
	for(int i=1;i<=a;i++)printf("%d ",n-a+i);
	for(int j=1;j<b;j++)
	{
		int len=((j<=r)?(t+1):t);
		for(int k=1;k<=len;k++)printf("%d ",cur-len+k);
		cur-=len;
	}
}
