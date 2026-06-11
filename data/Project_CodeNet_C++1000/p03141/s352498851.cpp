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
long long n,b_sum,a[100001],b[100001],c[100001],ans;
int main() 
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
      cin>>a[i]>>b[i];
      c[i]=a[i]+b[i];
      b_sum+=b[i];
   }
   sort(c,c+n);
   reverse(c,c+n);
   for(int i=0;i<n;i++)
   {
		if(i%2==0)
		{
			ans+=c[i];
    	}
   }
   ans-=b_sum;
   cout<<ans;
}