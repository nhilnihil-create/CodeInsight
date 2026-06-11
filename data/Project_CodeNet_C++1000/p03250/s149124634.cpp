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
int a,b,c; 
int main()
{
	cin>>a>>b>>c;
	cout<<a+b+c+max(a,max(b,c))*9;
}