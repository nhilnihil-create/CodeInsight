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
long long n,k,ans,t;
int main()
{
    cin>>n>>k;
    ans=n/k;
    ans=ans*ans*ans;
    if(!(k&1))
	{
		t=(n+k/2)/k;
		t=t*t*t;
	}
    cout<<ans+t;
}