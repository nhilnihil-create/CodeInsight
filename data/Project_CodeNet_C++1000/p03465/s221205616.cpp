#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
	x=0;
	char ch=getchar();
	int pd=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			pd=-pd;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=pd;
}
void write(const int &x)
{
	char ggg[10001];
	int s=0;
	int tmp=x;
	if(tmp==0)
	{
		putchar('0');
		return;
	}
	if(tmp<0)
	{
		tmp=-tmp;
		putchar('-');
	}
	while(tmp>0)
	{
		ggg[s++]=tmp%10+'0';
		tmp/=10;
	}
	while(s>0)
	{
		putchar(ggg[--s]);
	}
}
int n,sum;
bitset<4000010>f;
signed main()
{
	read(n);
	f[0]=1;
	for(register int i=1;i<=n;++i)
	{
		int x;
		read(x);
		f|=f<<x;
		sum+=x;
	}
	for(register int i=(sum+1)/2;i<=sum;++i)
	{
		if(f[i])
		{
			write(i);
			return 0;
		}
	}
} 