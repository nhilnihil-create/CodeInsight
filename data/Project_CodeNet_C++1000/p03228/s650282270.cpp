#include<bits/stdc++.h>
using namespace std;
namespace FAST_IO
{
	template<typename T> void read(T &a)
	{
		a=0;
		int f=1;
		char c=getchar();
		while(!isdigit(c))
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(isdigit(c))
		{
			a=a*10+c-'0';
			c=getchar();
		}
		a=a*f;
	}
	template <typename T> void write(T a)
	{
		if(a<0)
		{
			a=-a;
			putchar('-');
		}
		if(a>9)
		{
			write(a/10);
		}
		putchar(a%10+'0');
	}
	template <typename T> void writeln(T a)
	{
		write(a);
		puts("");
	}
}
int main()
{
	int a,b,k;
	cin>>a>>b>>k;
	for(int i=1;i<=k;i++)
	{
		if(i%2==1)
		{
			if(a%2==1)
			{
				a--;
			}
			a/=2;
			b+=a;
		}
		else
		{
			if(b%2==1)
			{
				b--;
			}
			b/=2;
			a+=b;			
		}
	}
	cout<<a<<" "<<b;
}