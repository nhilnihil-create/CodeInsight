#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
#include<cmath>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n;
int main()
{
	read(n);
	while(n--)
	{
		long long a,b;
		read(a);
		read(b);
		if(a==1 && b==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(a>b)	swap(a,b);
		long long s=a*b;
		long long gg=sqrt((long double)(s-1));
	//	cout<<s<<' '<<gg<<endl;
		long long sum=gg*2;
		if(gg==(s-1)/gg)	sum--;
		if(a<=gg)	sum--;
		cout<<sum<<endl;
	}
	return 0;
}