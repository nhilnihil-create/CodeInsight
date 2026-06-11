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
int a[200005],b[200005];
int d[200005];
int main()
{
	read(n);
	for(int i=0;i<n;i++)
		read(a[i]);
	for(int i=0;i<n;i++)
		read(b[i]);
	int ans=0;
	for(int bi=0;bi<=28;bi++)
	{
		long long cnt1=0;
		long long cnt2=0;
		for(int i=0;i<n;i++)
			cnt1+=((a[i]>>bi)&1);
		for(int i=0;i<n;i++)
			cnt2+=((b[i]>>bi)&1);
		long long sum=cnt1*(n-cnt2)+cnt2*(n-cnt1);
		for(int i=0;i<n;i++)
		{
			int now=a[i]&((1<<bi)-1);
			int ned=(1<<bi)-now-1;
			int pos=upper_bound(d,d+n,ned)-d;
		//	cout<<d[0]<<' '<<d[1]<<endl;
			sum+=n-pos;
		}//cout<<sum<<endl;
		for(int i=0;i<n;i++)
			d[i]=(b[i]&((1<<(bi+1))-1));
		sort(d,d+n);
		if(sum&1)	ans|=(1<<bi);
	}
	cout<<ans<<endl;
	return 0;
}