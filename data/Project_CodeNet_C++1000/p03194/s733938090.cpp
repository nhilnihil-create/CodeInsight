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
long long n, p,cnt[1000001],temp, ans = 1;
int main()
{

	cin>>n>>p;
	if (n == 1) 
	{
		cout<<p;
	}
	else
	{
		temp = p;
		for (long long i = 2; i*i<=temp;i++)
		{
			while (temp % i == 0)
			{
				temp /= i;
				cnt[i]++;
			}
		}
		for (long long i = 2; i*i<=p; i++)
		{
			for (int j = 0; j < cnt[i]/n; j++)
			{
				ans *= i;
			}
				
		}
		cout<<ans;
	}
}