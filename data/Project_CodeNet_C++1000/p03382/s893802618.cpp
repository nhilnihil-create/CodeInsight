#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
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
int a[100005];
int main()
{
	read(n);
	for(int i=0;i<n;i++)
		read(a[i]);
	sort(a,a+n);
	int kv=-1;
	int rv=-1;
	int mxx=a[n-1];
	for(int i=0;i<n-1;i++)
	{
		int nn=min(a[i],mxx-a[i]);
		if(nn>kv)
		{
			kv=nn;
			rv=a[i];
		}
	}
	printf("%d %d\n",a[n-1],rv);
	return 0;
}